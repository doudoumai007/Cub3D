#include "cub3D.h"

void	draw_minimap(t_data *data, int x, int y, int modifier)
{
	draw_border(data, x, y, modifier);
	draw_content(data, x, y, modifier);
	if (x == (int)data->map->player->current_position->y && \
		y == (int)data->map->player->current_position->x)
		draw_player(data,x, y, modifier);
}

void	minimap(t_data *data, int modifier)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->map_height)
	{
		x = 0;
		while (x < data->map->map_width)
		{
			draw_minimap(data, x, y, modifier);
			x++;
		}
		y++;
	}
}

void	raycasting(t_data *data)
{
	t_ray_casting	rc;
	int				x;//代表第x列

	rc.fov = M_PI / 3;
	rc.angle_step = rc.fov / data->img->width;
	rc.side = 0;
	x = data->img->width - 1;
	while (x >= 0)
	{
		init_ray_casting(&rc, data, data->img->width - 1 - x);//从0至x
		perform_dda(&rc, data);
		calculate_wall_properties(&rc, data);
		draw_vertical_line(data, x, rc.wall_height, &rc);
		x--;
	}
	if (data->map->minimap_display)
		minimap(data, HEIGHT / 80);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
