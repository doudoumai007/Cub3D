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

	n_line = 0;

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
		return (false);
	// check_map_valid();
	// check_color();
	// check_texture();
	return (true);
}
