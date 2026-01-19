#include "cub3D.h"

void	raycasting(t_data *data)
{
	t_ray_casting	rc;
	int				i;

	rc.fov = M_PI / 3;
	rc.angle_step = rc.fov / data->img->width;
	rc.side = 0;
	i = data->img->width - 1;
	while (i >= 0)
	{
		init_ray_casting(&rc, data, data->img->width - 1 - i);//从左至右
		perform_dda(&rc, data);
		i--;
	}
}
