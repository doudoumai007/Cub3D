#ifndef PARSING_H
# define PARSING_H

//texture
char	**split_line(char *line);
bool	fill_texture_data(char *line, t_textures *textures);
bool	fill_color(char *str, char c, t_textures *textures);
bool	fill_color_data(char *line, t_textures *textures);
bool	init_texture(t_data *data);
bool	parse_texture(int fd, t_data *data, int	*n_line);
char	*get_next_line_trim(int fd);

//initial
bool	init_texture(t_data *data);
void	init_data(t_data *data);
bool	init_map(t_data *data, int n_line);

//util
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isnumeric(char *str);
int		get_max_len(char **map_2d);
void	ft_copy(char *dest, char *src);

//free
void	free_tab(char **table);
void	free_texture(t_textures *textures);
void	free_player(t_player *player);
void	free_data(t_data *data);

//valid
bool	is_valid_color(char **color_tab);
bool	is_valid_filename(char *filename, char *ext);
bool	is_valid_texture(t_textures *textures);

//player
bool		is_player_char(char c);
t_vector	*set_player_pos(int i, int j, char c, t_player *player);
void		get_player(t_data *data);

//check_texture
bool	texture_ok(t_textures *textures);
bool	color_ok(t_textures *textures);
bool	check_texture(t_data *data);

//main
bool	parsing(char *filename, int ac, t_data *data);
bool	parse_map(int fd, t_data *data, int *n_line, char *filename);

#endif
