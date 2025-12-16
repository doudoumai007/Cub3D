#include "cub3D.h"

bool	init_texture(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	if (!data->texture)
		return (false);
	data->texture->no_file = NULL;
	data->texture->so_file = NULL;
	data->texture->we_file = NULL;
	data->texture->ea_file = NULL;
	data->texture->f_ok = 0;
	data->texture->c_ok = 0;
	data->texture->f_r = -1;
	data->texture->f_g = -1;
	data->texture->f_b = -1;
	data->texture->c_r = -1;
	data->texture->c_g = -1;
	data->texture->c_b = -1;
	return (true);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win =	NULL;
	// data->map = NULL;
	data->texture = NULL;
}
