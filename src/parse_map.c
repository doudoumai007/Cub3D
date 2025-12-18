#include "cub3D.h"

bool	is_map_line(char *line)
{
	int	i;

	if (line[0] == '\n')
		return (false);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("01EWSN ", line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_one_player(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr("EWSN", line[i]))
			data->map->n_player++;
	}
}

bool	init_map(t_data *data, int n_line)
{
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (false);
	data->map->map_height = data->n_line_file - n_line;
	data->map->map_width = 0;
	data->map->n_player = 0;
	data->map->map_2d = ft_calloc(data->map->map_height + 1, sizeof(char *));
	if (!data->map->map_2d)
		return (false);
	return (true);
}

int	get_total_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

bool	parse_map(int fd, t_data *data, int *n_line, char *filename)
{
	char	*line;

	data->n_line_file = get_total_lines(filename);
	line = get_next_line(fd);
	if (!line)
		return (false);
	while (line && !ft_strncmp("\n", line, 1))
	{
		free(line);
		line = get_next_line(fd);
		*n_line++;
	}
	if (!init_map(data, *n_line))
		return (false);
	while (line)
	{
		get_player(data);
		line = get_next_line(fd);
	}
	return (true);
}
