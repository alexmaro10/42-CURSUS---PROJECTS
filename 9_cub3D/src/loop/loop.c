/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:22:04 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/03 09:46:54 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_loop(t_game *game)
{
	move_player(game);
	raycast(game);
	return (0);
}

int	key_press(int keycode, t_game *game)
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
	if (keycode == KEY_ESC)
		close_game(game);
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
	if (keycode == KEY_LA)
		game->keys.left = 0;
	if (keycode == KEY_RA)
		game->keys.right = 0;
	return (0);
}
