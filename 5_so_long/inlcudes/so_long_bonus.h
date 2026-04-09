/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:54:06 by almaldon          #+#    #+#             */
/*   Updated: 2025/08/02 09:28:07 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// Standard libraries
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// External libraries
# include "MLX42/MLX42.h"
# include "libft.h"

// Window size
# define WIDTH 1920
# define HEIGHT 1080
# define BORDER_HEIGHT 30

// Tile size
# define TILE_SIZE 64

// Map tile characters
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define ENEMIE 'D'

typedef struct s_enemy
{
	int				enemy_x;
	int				enemy_y;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_player
{
	int			player_x;
	int			player_y;
	int			dir; //-1 izq, 1 der.
}	t_player;

typedef struct s_img
{
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player_current;
	mlx_image_t	*img_player_r;
	mlx_image_t	*img_player_r_s;
	mlx_image_t	*img_player_l;
	mlx_image_t	*img_player_l_s;
	mlx_image_t	*img_player_r_f1;
	mlx_image_t	*img_player_rs_f1;
	mlx_image_t	*img_player_l_f1;
	mlx_image_t	*img_player_ls_f1;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_exit_o;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_enemy;
	mlx_image_t	*img_0;
	mlx_image_t	*img_1;
	mlx_image_t	*img_2;
	mlx_image_t	*img_3;
	mlx_image_t	*img_4;
	mlx_image_t	*img_5;
	mlx_image_t	*img_6;
	mlx_image_t	*img_7;
	mlx_image_t	*img_8;
	mlx_image_t	*img_9;
}	t_img;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*edge;
	t_img		images;
	t_enemy		*enemy;
	char		**map;
	int			width;
	int			height;
	int			idle_frame;
	t_player	player;
	int			moves;
	int			enemies;
	int			col;
}	t_game;

typedef struct s_state
{
	int	collect;
	int	exit_reachable;
}	t_state;

//UTILS

void		ft_error(const char *msg);
void		free_map(char	**map);
char		**copy_map(char **map);
int			ft_count_rows(char **map);
void		print_enemy_list(t_enemy *head);
void		free_images(t_game *game);

//MAP

char		**read_map(char *file);
void		n_collect(char **map, int *collect);

//FILTER MAP
int			filter_map(t_game game);
int			check_map_char(char	**map);
int			rect_map(char **map, int rows, int colm);
int			req_min_map(char **map);
int			wall_borders(char **map, int rows, int colm);
void		flood_fill(int x, int y, t_state *state, char **map);
int			check_extension(char *map_name);

//PLAYER

void		coord_player(char **map, int *x, int *y);
void		updtae_animations(void *param);

//INIT

void		init_game(t_game *game);
bool		load_textures(t_game *game);
bool		load_tex(mlx_t *mlx, mlx_image_t **img, const char *path);

//RENDER

void		render_map(t_game *game);
void		display_steps(t_game *game);
void		clear_steps_area(t_game *game);
void		draw_enemy(t_game *game);
void		draw_tile(t_game *game, int x, int y);

//HOOK

void		handle_input(mlx_key_data_t keydata, void *param);
void		close_game(t_game *game);

//ENEMY
void		init_enemys(t_game *game);
void		free_lst(t_enemy **lst);

//ANIMATION
void		player_animation(t_game *game);
void		move_enemy(t_game *game, t_enemy *en);

//ANIMATION_EXTRA
void		update_mov(t_game *game);
void		move_enemies(t_game *game);
#endif
