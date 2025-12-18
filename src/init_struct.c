#include "cub3D.h"

bool	init_texture(t_data *data)
{
	data->textures = malloc(sizeof(t_textures));
	if (!data->textures)
		return (false);
	data->textures->no_file = NULL;
	data->textures->so_file = NULL;
	data->textures->we_file = NULL;
	data->textures->ea_file = NULL;
	data->textures->f_ok = 0;
	data->textures->c_ok = 0;
	data->textures->f_r = -1;
	data->textures->f_g = -1;
	data->textures->f_b = -1;
	data->textures->c_r = -1;
	data->textures->c_g = -1;
	data->textures->c_b = -1;
	return (true);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win =	NULL;
	data->map = NULL;
	data->textures = NULL;
}
