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
			{
				printf("[DEBUG]: wrong character %c", map_2d[i][j]);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	flood_fill(t_map *map, int x, int y)
{
	char **map_2d;

	map_2d = map->map_2d;
	if (!x || !y || x == map->map_width - 1 || y == map->map_height - 1 \
		|| map_2d[x][y] == ' ')
		return (false);
	if (map_2d[x][y] == '1' || map_2d[x][y] == 'V')
		return (true);
	map_2d[x][y] = 'V';
	if (flood_fill(map, x - 1, y))
		return (false);
	if (flood_fill(map, x + 1, y))
		return (false);
	if (flood_fill(map, x, y - 1))
		return (false);
	if (flood_fill(map, x, y + 1))
		return (false);
	return (true);
}

void	debug_map(char **map)
{
	int	i = 0;

	printf("[DEBUG MAP]\n");
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

bool	check_map(t_data *data)
{
	// debug_map(data->map->map_2d);
	if (!data->map->n_player)
		return (write(2, "Error\nNo player in the map\n", 28), false);
	if (data->map->n_player > 1)
		return (write(2, "Error\nMore than 1 player in the map\n", 37), false);
	if (!check_map_character(data->map->map_2d))
		return (write(2, "Error\nInvalid character in the map\n", 36), false);
	if (!flood_fill(data->map, data->map->player_x, data->map->player_y))
		return (write(2, "Error\nMap unclosed\n", 20), false);
	return (true);
}

bool	check_file(int fd, char *filename, t_data *data)
{
	int	n_line;

	(void)filename;
	data->n_line_file = get_total_lines(filename);
	n_line = 0;
	if (!init_texture(data))
		return (false);
	if (!parse_texture(fd, data, &n_line))
		return(write(2, "Error\nInvalid texture\n", 22), false);
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
	// if (!check_map_valid(data))
	// 	return (false);
	// check_color();
	// check_texture();
	close(fd);
	return (true);
}
