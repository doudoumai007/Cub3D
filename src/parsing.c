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

bool	check_file(int fd, char *filename, t_data *data)
{
	int	n_line;

	(void)filename;
	n_line = 0;
//	data->n_line_file = ft_get_nb_lines(filename);
	if (!init_texture(data))
		return (false);
	if (!parse_texture(fd, data, &n_line))
		return(perror("Error\nInvalid texture\n"), false);
	if (!parse_map(fd, data, &n_line, filename))
		return (false);
	if (!check_map(data))
		return (false);
	return (true);
}

bool	parsing(char *filename, int ac, t_data *data)
{
	int	fd;

	if (ac != 2)
		return (perror("Error\nInvalid number of arguments\n"), false);
	if (!check_extension(filename))
		return (perror("Error\nInvalid file name or extension\n"), false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nFile cannot open\n"), false);
	if (!check_file(fd, filename, data))
	{
		if (fd > 0)
			close(fd);
		return (false);
	}
	if (!check_map_valid(data))
		return (false);
	// check_color();
	// check_texture();
	close(fd);
	return (true);
}
