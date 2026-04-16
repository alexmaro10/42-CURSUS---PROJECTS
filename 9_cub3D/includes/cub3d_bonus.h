/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:01:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:22:40 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include <mlx.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define YELLOW "\x1B[33m"
# define BLUE "\x1b[1;36m"
# define RED "\x1b[1;31m"
# define RESET "\033[0m"

# define KEY_E 101
# define KEY_R 114
# define KEY_Q 113
# define KEY_M 109
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LA 65361
# define KEY_RA 65363
# define KEY_ESC 65307
# define KEY_PLUS 65451
# define KEY_MINUS 65453

# define FOV_VALUE 60.f
# define COLLISION_DIST 0.1
# define WIN_W 1280
# define WIN_H 720

# define MINIMAP_SCALE 15
# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		d;
	int		color;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		step_x;
	int		step_y;
	int		hit;
	char	hit_type;
	int		side;
	int		map_x;
	int		map_y;
}	t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_player_data
{
	int		y;
	int		x;
	char	dir;
}	t_player_data;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	angle;
}	t_player;

typedef struct s_map_data
{
	int				map_init_line;
	int				no_line;
	int				so_line;
	int				we_line;
	int				ea_line;
	int				sp_line;
	int				d_line;
	int				f_line;
	int				c_line;
	char			**only_map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	char			*d;
	char			*f;
	char			*c;
	int				f_color;
	int				c_color;
	t_player_data	player_data;
}	t_map_data;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
	int	q;
	int	e;
	int	r;
	int	m;
}	t_keys;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_triangle
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
}	t_triangle;

typedef struct s_game
{
	char		**map;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_texture	door;
	t_mlx		mlx;
	t_player	player;
	t_keys		keys;
	t_map_data	map_data;
}	t_game;

//ARG_VALIDATION.C
int			check_args(char *argv, int argc);
void		free_game(t_game *game);

//MAP_VALIDATION.C
int			valid_map(char **map, t_map_data *map_data);
int			is_sorrounded(char **map, int i, int j, t_map_data *map_data);
int			is_zero_sorrounded(char **map, int i, int j, t_map_data *map_data);
int			only_one_player(char **map, t_map_data *map_data);
int			surrounded_map(char **map, t_map_data *map_data);
int			not_void(char **map, t_map_data *map_data);
int			exist_token(char **map, t_map_data *map_data);
int			valid_spaces(char **map, t_map_data *map_data);

//UTILS.C
int			ft_exit(int n, char *msg);
int			ft_maplen(char **map);
int			extract_colours_f(char **map, t_map_data *map_data);
int			extract_colours_c(char **map, t_map_data *map_data);
int			extract_no(char **map, t_map_data *map_data);
int			extract_so(char **map, t_map_data *map_data);
int			extract_we(char **map, t_map_data *map_data);
int			extract_ea(char **map, t_map_data *map_data);
int			extract_d(char **map, t_map_data *map_data);
int			rgb_to_int(char *colors);
int			close_game(t_game *game);
int			key_hook(int keycode, t_game *game);
char		*ft_strdup_no_nl(const char *s);
char		**file_to_charpp(const char *path);
void		ft_free_map(char **map);
void		ft_free_struct(t_map_data *map_data);
void		put_pixel(t_game *game, int x, int y, int color);
int			get_line_len(char *line);

//INIT.C
int			fill_structures(char **map, t_map_data *map_data);
int			init_mlx(t_game *game);
char		**extract_map(char **file, int map_start);
void		init_player_keys(t_game *game);
void		init_map_data(t_map_data *map_data);

//INIT_KEYS.C
void		init_keys(t_game *game);

//INIT_RAY.C
void		init_ray(t_game *game, int x, t_ray *ray);

//RAYCAST.C
void		raycast(t_game *game);
void		dda_protect(t_game *game, t_ray *ray);
void		calculate_perp_distance(t_game *game, t_ray *ray);

//LOOP.C
int			game_loop(t_game *game);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);

//MOVEMENT.C
void		move_player(t_game *game);

//ROTATION.C
void		rot_left(double rot_speed, t_game *game);
void		rot_right(double rot_speed, t_game *game);

//ACTIONS.C
int			mouse_move(int x, int y, t_game *game);
void		unlock_door(t_game *game);
void		lock_door(t_game *game);

//TEXTURES.C
int			load_texture(void *mlx, t_texture *tex, char *path);
int			get_tex_pixel(t_texture *tex, int x, int y);
t_texture	*texture_selector(t_game *game, t_ray *ray);
void		draw_textures(t_game *game, int x, t_ray *ray, t_texture *tex);

//MINIMAP.C
void		draw_minimap(t_game *game);
void		draw_player_direction(t_game *game);
void		draw_player_triangle(t_game *game);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
#endif