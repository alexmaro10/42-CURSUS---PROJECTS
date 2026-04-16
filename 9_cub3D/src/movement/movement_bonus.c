/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:00:27 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:00:27 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	can_move(double x, double y, t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (game->map_data.only_map[map_y][map_x] == '1'
		|| game->map_data.only_map[map_y][map_x] == 'D')
		return (0);
	if (x - map_x < COLLISION_DIST
		&& (game->map_data.only_map[map_y][map_x - 1] == '1'
		|| game->map_data.only_map[map_y][map_x - 1] == 'D'))
		return (0);
	if (map_x + 1 - x < COLLISION_DIST
		&& (game->map_data.only_map[map_y][map_x + 1] == '1'
		|| game->map_data.only_map[map_y][map_x + 1] == 'D'))
		return (0);
	if (y - map_y < COLLISION_DIST
		&& (game->map_data.only_map[map_y - 1][map_x] == '1'
		|| game->map_data.only_map[map_y - 1][map_x] == 'D'))
		return (0);
	if (map_y + 1 - y < COLLISION_DIST
		&& (game->map_data.only_map[map_y + 1][map_x] == '1'
		|| game->map_data.only_map[map_y + 1][map_x] == 'D'))
		return (0);
	return (1);
}

static void	move_up_down(double move_speed, t_game *game, int id)
{
	double	nx;
	double	ny;

	if (id == 1)
	{
		nx = game->player.pos_x - game->player.dir_x * move_speed;
		ny = game->player.pos_y - game->player.dir_y * move_speed;
		if (can_move(nx, game->player.pos_y, game))
			game->player.pos_x = nx;
		if (can_move(game->player.pos_x, ny, game))
			game->player.pos_y = ny;
	}
	else
	{
		nx = game->player.pos_x + game->player.dir_x * move_speed;
		ny = game->player.pos_y + game->player.dir_y * move_speed;
		if (can_move(nx, game->player.pos_y, game))
			game->player.pos_x = nx;
		if (can_move(game->player.pos_x, ny, game))
			game->player.pos_y = ny;
	}
}

static void	move_left(double move_speed, t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.pos_x - game->player.plane_x * move_speed;
	ny = game->player.pos_y - game->player.plane_y * move_speed;
	if (can_move(nx, game->player.pos_y, game))
		game->player.pos_x = nx;
	if (can_move(game->player.pos_x, ny, game))
		game->player.pos_y = ny;
}

static void	move_right(double move_speed, t_game *game)
{
	double	nx;
	double	ny;

	nx = game->player.pos_x + game->player.plane_x * move_speed;
	ny = game->player.pos_y + game->player.plane_y * move_speed;
	if (can_move(nx, game->player.pos_y, game))
		game->player.pos_x = nx;
	if (can_move(game->player.pos_x, ny, game))
		game->player.pos_y = ny;
}

void	move_player(t_game *game)
{
	double	move_speed;
	double	rot_speed;

	rot_speed = 0.02;
	move_speed = 0.05;
	if (game->keys.e)
		unlock_door(game);
	if (game->keys.r)
		lock_door(game);
	if (game->keys.w)
		move_up_down(move_speed, game, 0);
	if (game->keys.s)
		move_up_down(move_speed, game, 1);
	if (game->keys.a)
		move_left(move_speed, game);
	if (game->keys.d)
		move_right(move_speed, game);
	if (game->keys.left)
		rot_left(rot_speed, game);
	if (game->keys.right)
		rot_right(rot_speed, game);
}
