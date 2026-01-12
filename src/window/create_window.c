#include "cub3D.h"

bool	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error\nmlx_init failed\n");
		return(false);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	
}

bool	create_window(t_data *data)
{
	if (!init_mlx(data))
		return (false);
	return (true);
}
