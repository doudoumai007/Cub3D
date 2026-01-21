#include "cub3D.h"

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
}
