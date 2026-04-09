/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:14:14 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/25 09:19:20 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

static void	player_animation2(t_game *game, int *framecount)
{
	if (*framecount == game->idle_frame)
	{
		game->images.img_player_current = game->images.img_player_r_f1;
		mlx_image_to_window(game->mlx, game->images.img_player_current,
			game->player.player_x * TILE_SIZE,
			game->player.player_y * TILE_SIZE);
	}
	else if (*framecount >= game->idle_frame * 2)
	{
		game->images.img_player_current = game->images.img_player_r;
		mlx_image_to_window(game->mlx, game->images.img_player_current,
			game->player.player_x * TILE_SIZE,
			game->player.player_y * TILE_SIZE);
		*framecount = 0;
	}
}

void	player_animation(t_game *game)
{
	static int	framecount = 0;

	if (!game || !game->images.img_collect || !game->images.img_player_l)
		return ;
	if (game->player.dir == -1)
	{
		if (framecount == game->idle_frame)
		{
			game->images.img_player_current = game->images.img_player_l_f1;
			mlx_image_to_window(game->mlx, game->images.img_player_current,
				game->player.player_x * TILE_SIZE,
				game->player.player_y * TILE_SIZE);
		}
		else if (framecount >= game->idle_frame * 2)
		{
			game->images.img_player_current = game->images.img_player_l;
			mlx_image_to_window(game->mlx, game->images.img_player_current,
				game->player.player_x * TILE_SIZE,
				game->player.player_y * TILE_SIZE);
			framecount = 0;
		}
	}
	else
		player_animation2(game, &framecount);
	framecount++;
}

int	try_move_enemy(t_game *game, t_enemy *en, int dy, int dx)
{
	int	new_y;
	int	new_x;

	new_x = en->enemy_x + dx;
	new_y = en->enemy_y + dy;
	if (game->map[new_y][new_x] == FLOOR ||
		(game->map[new_y][new_x] == PLAYER && game->col != 0))
	{
		if (game->map[new_y][new_x] == PLAYER)
		{
			ft_printf("\033[1;31mENEMY KILL YOU.\033[0m\n");
			close_game(game);
		}
		game->map[en->enemy_y][en->enemy_x] = FLOOR;
		game->map[new_y][new_x] = ENEMIE;
		en->enemy_y = new_y;
		en->enemy_x = new_x;
		return (1);
	}
	return (0);
}

int	move_enemy_towards_player(t_game *game, t_enemy *en)
{
	int	y;
	int	x;

	y = en->enemy_y;
	x = en->enemy_x;
	if (x == game->player.player_x && y > game->player.player_y)
		return (try_move_enemy(game, en, -1, 0));
	if (x == game->player.player_x && y < game->player.player_y)
		return (try_move_enemy(game, en, 1, 0));
	if (y == game->player.player_y && x > game->player.player_x)
		return (try_move_enemy(game, en, 0, -1));
	if (y == game->player.player_y && x > game->player.player_x)
		return (try_move_enemy(game, en, 0, 1));
	return (0);
}

void	move_enemy(t_game *game, t_enemy *en)
{
	if (move_enemy_towards_player(game, en))
		return ;
	if (try_move_enemy(game, en, 0, 1))
		return ;
	if (try_move_enemy(game, en, 0, -1))
		return ;
	if (try_move_enemy(game, en, 1, 0))
		return ;
	if (try_move_enemy(game, en, -1, 0))
		return ;
}
