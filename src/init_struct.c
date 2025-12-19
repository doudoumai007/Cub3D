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

bool	init_map(t_data *data, int n_line)
{
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (false);
	data->map->player = ft_calloc(1, sizeof(t_player));
	if (!data->map->player)
		return(false);
	data->map->player->current_position = NULL;
	data->map->player->start_position = NULL;
	data->map->player->move_forward = 0;
	data->map->player->move_backward = 0;
	data->map->player->move_left = 0;
	data->map->player->move_right = 0;
	data->map->player->rotate_left = 0;
	data->map->player->rotate_right = 0;
	data->map->map_height = data->n_line_file - n_line;
	data->map->map_width = 0;
	data->map->n_player = 0;
	data->map->map_2d = ft_calloc(data->map->map_height + 1, sizeof(char *));
	if (!data->map->map_2d)
		return (false);
	return (true);
}
