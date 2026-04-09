/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:25 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/25 12:10:10 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

static void	sprite_control(int dx, t_game *game)
{
	if (dx == -1)
	{
		game->images.img_player_current = game->images.img_player_l;
		game->player.dir = -1;
	}
	else if (dx == 1)
	{
		game->player.dir = 1;
		game->images.img_player_current = game->images.img_player_r;
	}
}

static void	collision_control(t_game *game, int new_x, int new_y, char tile)
{
	if (tile == COLLECTIBLE)
	{
		game->col--;
		game->map[new_y][new_x] = FLOOR;
		if (game->col == 0)
		{
			game->images.img_player_r = game->images.img_player_r_s;
			game->images.img_player_r_f1 = game->images.img_player_rs_f1;
			game->images.img_player_l = game->images.img_player_l_s;
			game->images.img_player_l_f1 = game->images.img_player_ls_f1;
			render_map(game);
		}
	}
	else if (tile == EXIT && game->col == 0)
	{
		ft_printf("\033[1;92mYOU HAVE WON IN %d MOVES!\033[0m\n", game->moves);
		close_game(game);
	}
	else if (tile == ENEMIE && game->col == 0)
		game->map[new_y][new_x] = FLOOR;
	else if (tile == ENEMIE)
	{
		ft_printf("\033[1;31mENEMY KILL YOU.\033[0m\n");
		close_game(game);
	}
}

static void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player.player_x + dx;
	new_y = game->player.player_y + dy;
	sprite_control(dx, game);
	tile = game->map[new_y][new_x];
	if (tile == WALL || (tile == EXIT && game->col != 0))
		return ;
	game->moves++;
	collision_control(game, new_x, new_y, tile);
	game->player.player_x = new_x;
	game->player.player_y = new_y;
	game->map[new_y - dy][new_x - dx] = FLOOR;
	game->map[new_y][new_x] = PLAYER;
	mlx_image_to_window(game->mlx, game->images.img_player_current,
		game->player.player_x * TILE_SIZE, game->player.player_y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->images.img_floor,
		(game->player.player_x - dx) * TILE_SIZE,
		(game->player.player_y - dy) * TILE_SIZE);
	update_mov(game);
}

void	close_game(t_game *game)
{
	free_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
	free_lst(&game->enemy);
	exit(EXIT_FAILURE);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, 1, 0);
}
