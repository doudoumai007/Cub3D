#ifndef STRUCT_H
# define STRUCT_H

# include "../minilibx-linux/mlx_int.h"

typedef struct s_textures
{
	char	*no_file;
	char	*so_file;
	char	*we_file;
	char	*ea_file;
	int		f_ok;
	int		c_ok;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
}	t_textures;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef	struct s_player
{
	t_vector	*start_position;
	t_vector	*current_position;
	double		delta_x;
	double		delta_y;
	double		rotation;
//	int			player_count;
	int			move_forward;
	int			move_backward;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		line_length;
}	t_texture;

typedef struct s_map
{
	char		**map_2d;
	int			map_height;
	int			map_width;
	int			n_player;
	int			player_x;
	int			player_y;
	t_player	*player;
	t_texture	*textures[4];
	bool		minimap_display;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_textures	*textures;
	t_map		*map;
//	t_img		*img;
	int			n_line_file;
}	t_data;

#endif
