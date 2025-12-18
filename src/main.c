#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(data);
	if (!parsing(av[1], ac, data))
	{
		free_data(data);
		return(1);
	}
//	if (!create_window())
	// {
	// 	free_data(data);
	// 	return(1);
	// }
	free_data(data);
	return (0);
}
