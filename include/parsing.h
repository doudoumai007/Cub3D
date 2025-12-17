#ifndef PARSING_H
# define PARSING_H

bool	parsing(char *filename, int ac, t_data *data);
bool	parse_map(int fd, t_data *data, int *n_line);

#endif
