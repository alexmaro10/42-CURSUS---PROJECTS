/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:54:06 by almaldon          #+#    #+#             */
/*   Updated: 2025/08/02 08:59:34 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Standard libraries
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// External libraries
# include "MLX42/MLX42.h"
# include "../libft/libft.h"

// Window size
# define WIDTH 800
# define HEIGHT 600

// Tile size
# define TILE_SIZE 64

// Map tile characters
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player_current;
	mlx_image_t	*img_player_r;
	mlx_image_t	*img_player_l;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collect;
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			moves;
	int			collectibles;
}	t_game;

typedef struct s_state
{
	int	collect;
	int	exit_reachable;
}	t_state;

//UTILS

void	ft_error(const char *msg);
void	free_map(char	**map);
char	**copy_map(char **map);
int		ft_count_rows(char **map);

//MAP

char	**read_map(char *file);
void	n_collect(char **map, int *collect);

//FILTER MAP
int		filter_map(t_game game);
int		check_map_char(char	**map);
int		rect_map(char **map, int rows, int colm);
int		req_min_map(char **map);
int		wall_borders(char **map, int rows, int colm);
void	flood_fill(int x, int y, t_state *state, char **map);
int		check_extension(char *map_name);

//PLAYER

void	coord_player(char **map, int *x, int *y);

//INIT

void	init_game(t_game *game);
bool	load_textures(t_game *game);

//RENDER

void	render_map(t_game *game);
void	display_steps(t_game *game);
void	clear_steps_area(t_game *game);

//HOOK

void	handle_input(mlx_key_data_t keydata, void *param);
void	close_game(t_game *game);

#endif
