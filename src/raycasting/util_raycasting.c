#include "cub3D.h"

void	init_step_distance(t_ray_casting *rc)
{
	if (rc->dir_x < 0)//射线向左，即第二三象限
	{
		rc->step_x = -1;//x方向移动-1格
		rc->side_dist_x = (rc->ray_x - rc->map_x) * rc->delta_dist_x;
	}
	else//射线向右，即第一四象限
	{
		rc->step_x = 1;//x方向移动+1格
		rc->side_dist_x = (rc->map_x + 1.0f - rc->ray_x) * rc->delta_dist_x;
	}
	if (rc->dir_y < 0)//射线向上，即第一二象限
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->ray_y - rc->map_y) *rc->delta_dist_y;
	}
	else//射线向下，即第三四象限
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0f - rc->ray_y) * rc->delta_dist_y;
	}
}

void	init_ray_casting(t_ray_casting *rc, t_data *data, int i)
{
	rc->ray_angle = data->map->player->rotation - (rc->fov / 2) \
		+ (i * rc->angle_step);
	rc->ray_x = data->map->player->current_position->y;
	rc->ray_y = data->map->player->current_position->x;
	rc->dir_x = cos(-rc->ray_angle);
	rc->dir_y = sin(-rc->ray_angle);//y反转，符合向下为正的屏幕坐标系
	rc->delta_dist_x = fabs(1.0f / rc->dir_x);
	rc->delta_dist_y = fabs(1.0f / rc->dir_y);
	rc->map_x = (int)rc->ray_x;
	rc->map_y = (int)rc->ray_y;
	init_step_distance(rc);
}

void	perform_dda(t_ray_casting *rc, t_data *data)
{
	rc->hit = 0;
	while (!rc->hit && rc->map_x >=0 && rc->map_x < data->map->map_width
		&& rc->map_y >= 0 && rc->map_y < data->map->map_height)
	{
		if (rc->side_dist_x < rc->side_dist_y)//x更短，先碰墙
		{
			rc->side_dist_x += rc->delta_dist_x; //往左右走一格
			rc->map_x += rc->step_x;
			rc->side = 0;//x轴碰墙flag
		}
		else//y更短，先碰墙
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;//y轴碰墙flag
		}
		if (rc->map_x >= 0 && rc->map_x < data->map->map_width
			&& rc->map_y >=0 && rc->map_y < data->map->map_height
			&& data->map->map_2d[rc->map_y][rc->map_x] == '1')//碰墙
			rc->hit = 1;
	}
}
