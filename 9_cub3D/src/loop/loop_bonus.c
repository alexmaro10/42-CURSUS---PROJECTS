/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:22:04 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:56:34 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	game_loop(t_game *game)
{
	move_player(game);
	raycast(game);
	if (game->keys.q == 1)
	{
		mlx_mouse_hide(game->mlx.mlx, game->mlx.win);
		mlx_mouse_move(game->mlx.mlx, game->mlx.win, WIN_W / 2, WIN_H / 2);
	}
	else
		mlx_mouse_show(game->mlx.mlx, game->mlx.win);
	if (game->keys.m == 1)
	{
		draw_minimap(game);
		draw_player_triangle(game);
		mlx_put_image_to_window(game->mlx.mlx,
			game->mlx.win, game->mlx.img, 0, 0);
	}
	return (0);
}

static void	action_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_Q)
	{
		if (game->keys.q == 0)
			game->keys.q = 1;
		else
			game->keys.q = 0;
	}
	if (keycode == KEY_M)
	{
		if (game->keys.m == 0)
			game->keys.m = 1;
		else
			game->keys.m = 0;
	}
	if (keycode == KEY_R)
		game->keys.r = 1;
	if (keycode == KEY_E)
		game->keys.e = 1;
	if (keycode == KEY_ESC)
		close_game(game);
}

static void	movement_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 1;
	if (keycode == KEY_S)
		game->keys.s = 1;
	if (keycode == KEY_A)
		game->keys.a = 1;
	if (keycode == KEY_D)
		game->keys.d = 1;
	if (keycode == KEY_LA)
		game->keys.left = 1;
	if (keycode == KEY_RA)
		game->keys.right = 1;
}

int	key_press(int keycode, t_game *game)
{
	movement_key_press(keycode, game);
	action_key_press(keycode, game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	if (keycode == KEY_S)
		game->keys.s = 0;
	if (keycode == KEY_A)
		game->keys.a = 0;
	if (keycode == KEY_D)
		game->keys.d = 0;
	if (keycode == KEY_R)
		game->keys.r = 0;
	if (keycode == KEY_E)
		game->keys.e = 0;
	if (keycode == KEY_LA)
		game->keys.left = 0;
	if (keycode == KEY_RA)
		game->keys.right = 0;
	return (0);
}
