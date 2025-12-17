#include "cub3D.h"

bool	is_valid_color(char **color_tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!color_tab[i] || !ft_isnumeric(color_tab[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_filename(char *filename, char *ext)
{
	if ((!filename || ft_strlen(filename) < 4 ) || \
		(ft_strcmp(filename + ft_strlen(filename) - 4, ext)))
		return (false);
	return (true);
}

bool	is_valid_texture(t_texture *texture)
{
	int	valid;
	int	file_name;

	valid = texture->no_file && texture->so_file && \
			texture->we_file && texture->ea_file;
	file_name = is_valid_filename(texture->no_file, ".xpm") && \
				is_valid_filename(texture->so_file, ".xpm") && \
				is_valid_filename(texture->we_file, ".xpm") && \
				is_valid_filename(texture->ea_file, ".xpm");
	return (valid && file_name);
}
