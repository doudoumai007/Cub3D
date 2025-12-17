#ifndef PARSING_H
# define PARSING_H

//texture
char	**split_line(char *line);
bool	fill_texture_data(char *line, t_texture *texture);
bool	fill_color(char *str, char c, t_texture *texture);
bool	fill_color_data(char *line, t_texture *texture);
bool	init_texture(t_data *data);
bool	parse_texture(int fd, t_data *data, int	*n_line);
char	*get_next_line_trim(int fd);

//initial
void	init_data(t_data *data);

//util
int	ft_strcmp(const char *s1, const char *s2);
int	ft_isnumeric(char *str);

//free
void	free_tab(char **table);

//valid
bool	is_valid_color(char **color_tab);
bool	is_valid_filename(char *filename, char *ext);
bool	is_valid_texture(t_texture *texture);

//main
bool	parsing(char *filename, int ac, t_data *data);

#endif
