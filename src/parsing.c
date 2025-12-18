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

bool	check_map(t_data *data)
{
	if (!data->map->n_player)
		return (perror("Error\nNo player in the map\n"), false);
	if (data->map->n_player > 1)
		return (perror("Error\nMore than 1 player in the map\n"), false);
	if (!check_map_character(data->map->map_2d))
		return (perror("Error\nInvalid character in the map\n"), false);
	return (true);
}

bool	check_file(int fd, char *filename, t_data *data)
{
	int	n_line;

	(void)filename;
	n_line = 0;
	if (!init_texture(data))
		return (false);
	if (!parse_texture(fd, data, &n_line))
		return(write(2, "Error\nInvalid texture\n", 22), false);
	if (!parse_map(fd, data, &n_line, filename))
		return (false);
	// if (!check_map(data))
	// 	return (false);
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
