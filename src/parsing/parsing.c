#include "cub3D.h"

bool	check_extension(char *filename)
{
	if (!filename)
		return (false);
	if (ft_strlen(filename) < 4)
		return (false);
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

bool	check_map_character(char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (!ft_strchr("01EWSN ", map_2d[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	flood_fill(t_map *map, char **map_2d, int x, int y)
{
	//先判断x和y是否有效，然后再读取map_2d[x][y],否则会出现segfault
	if (x < 0 || y < 0|| x >= map->map_height || y >= map->map_width \
		|| map_2d[x][y] == ' ')
	{
//		printf("[DEBUG] x:%d y:%d c:%c\n", x, y, map_2d[x][y]);
		return (false);
	}
	if (map_2d[x][y] == '1' || map_2d[x][y] == 'V')
		return (true);
	map_2d[x][y] = 'V';
	if (!flood_fill(map, map_2d, x - 1, y))
		return (false);
	if (!flood_fill(map, map_2d, x + 1, y))
		return (false);
	if (!flood_fill(map, map_2d, x, y - 1))
		return (false);
	if (!flood_fill(map, map_2d, x, y + 1))
		return (false);
	return (true);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**dup_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->map_height)
	{
		copy[i] = ft_strdup(map->map_2d[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[map->map_height] = NULL;
	return (copy);
}

bool	check_map(t_data *data)
{
	char	**copy;

	// debug_map(data->map->map_2d);
	// printf("[DEBUG]: height %d\n", data->map->map_height);
	// printf("[DEBUG]: width %d\n", data->map->map_width);
	copy = dup_map(data->map);
	if (!copy)
		return (false);
	if (!data->map->n_player)
		return (write(2, "Error\nNo player in the map\n", 28), false);
	if (data->map->n_player > 1)
		return (write(2, "Error\nMore than 1 player in the map\n", 37), false);
	if (!check_map_character(data->map->map_2d))
		return (write(2, "Error\nInvalid character in the map\n", 36), false);
	if (!flood_fill(data->map, copy, data->map->player_x, data->map->player_y))
	{
		free_map(copy);
		return (write(2, "Error\nMap unclosed\n", 20), false);
	}
	// debug_map(copy);
	free_map(copy);
	return (true);
}

bool	check_file(int fd, char *filename, t_data *data)
{
	int	n_line;

	data->n_line_file = get_total_lines(filename);
	n_line = 0;
	if (!init_texture(data))
		return (false);
	if (!parse_texture(fd, data, &n_line))
		return(write(2, "Error\nInvalid texture\n", 22), false);
	if (!check_texture(data))
		return(false);
	if (!parse_map(fd, data, &n_line))
		return (false);
	if (!check_map(data))
		return (false);
	return (true);
}

bool	parsing(char *filename, int ac, t_data *data)
{
	int	fd;

	if (ac != 2)
		return (write(2, "Error\nInvalid number of arguments\n", 34), false);
	if (!check_extension(filename))
		return (write(2, "Error\nInvalid file name or extension\n", 37), false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nFile cannot open\n", 23), false);
	if (!check_file(fd, filename, data))
	{
		if (fd > 0)
			close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
