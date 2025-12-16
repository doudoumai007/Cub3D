#include "cub3D.h"

bool	parse_texture(int fd, t_data *data, int	*n_line)
{
	char	*line;

	line = get_next_line_trim(fd);
	if (!line)
		return(false);
	while (line)
	{
		(*n_line)++;
		
	}
}
