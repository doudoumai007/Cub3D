#ifndef STRUCT_H
# define STRUCT_H

//# include "../mlx_linux/mlx_init.h"

// typedef struct s_map
// {

// }	t_map;

typedef struct s_texture
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
}	t_texture;

typedef struct s_map
{
	char			**map_2d;
	int				map_height;
	int				map_width;
	int				n_player;
	struct s_player	*player;
	// t_texture		*textures[4];
	// bool			minimap_display;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_texture	*texture;
//	t_img		*img;
	int			n_line_file;
}	t_data;


#endif
