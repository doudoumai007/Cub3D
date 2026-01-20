#define WIDTH 1920
#define HEIGHT 1080

#define ESC 65307
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

//window.c
bool	create_window(t_data *data);
bool	init_mlx_window(t_data *data);

//texture.c
bool	load_texture(t_data *data);
void	texture_loaded(t_data *data, t_texture **t, char *filename);

//key.c
int		close_window(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

//raycasting
void	raycasting(t_data *data);
void	init_step_distance(t_ray_casting *rc);
void	init_ray_casting(t_ray_casting *rc, t_data *data, int i);
void	perform_dda(t_ray_casting *rc, t_data *data);

//wall.c
float	calculate_wall_dist(t_ray_casting *rc);
float	normalize_angle_diff(float angle_diff);
void	calculate_wall_properties(t_ray_casting *rc, t_data *data);

//game.c
int		game_loop(t_data *data);
void	handle_forward(t_data *data, t_player *player, float move_speed);
void	handle_backward(t_data *data, t_player *player, float move_speed);
void	handle_side(t_data *data, t_player *player, float move_speed, int dir);
void	handle_rotation(t_player *player, float rotation_speed, int dir);
