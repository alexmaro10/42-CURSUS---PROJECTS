/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:36:40 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/25 09:40:53 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == WALL)
		mlx_image_to_window(game->mlx, game->images.img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == FLOOR)
		mlx_image_to_window(game->mlx, game->images.img_floor,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_image_to_window(game->mlx, game->images.img_collect,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_image_to_window(game->mlx, game->images.img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == ENEMIE)
		mlx_image_to_window(game->mlx, game->images.img_enemy,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_e(t_game *game, int x, int y)
{
	char	tile[5];

	tile[0] = game->map[y][x];
	tile[1] = game->map[y - 1][x];
	tile[2] = game->map[y + 1][x];
	tile[3] = game->map[y][x - 1];
	tile[4] = game->map[y][x + 1];
	if (tile[0] == ENEMIE)
	{
		mlx_image_to_window(game->mlx, game->images.img_enemy,
			x * TILE_SIZE, y * TILE_SIZE);
		if (tile[1] && tile[1] == FLOOR)
			mlx_image_to_window(game->mlx, game->images.img_floor,
				x * TILE_SIZE, (y - 1) * TILE_SIZE);
		if (tile[2] && tile[2] == FLOOR)
			mlx_image_to_window(game->mlx, game->images.img_floor,
				x * TILE_SIZE, (y + 1) * TILE_SIZE);
		if (tile[3] && tile[3] == FLOOR)
			mlx_image_to_window(game->mlx, game->images.img_floor,
				(x - 1) * TILE_SIZE, y * TILE_SIZE);
		if (tile[4] && tile[4] == FLOOR)
			mlx_image_to_window(game->mlx, game->images.img_floor,
				(x + 1) * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	render_map_ini(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			draw_tile(game, x, y);
		}
	}
	mlx_image_to_window(game->mlx, game->images.img_player_current,
		game->player.player_x * TILE_SIZE,
		game->player.player_y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->images.img_0,
		0 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->images.img_0,
		1 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->images.img_0,
		2 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
}

static void	render_exit(t_game *game, int x, int y)
{
	static int	count = 0;

	if (count == 0)
	{
		mlx_image_to_window(game->mlx, game->images.img_exit_o,
			x * TILE_SIZE, y * TILE_SIZE);
	}
	count++;
}

void	render_map(t_game *game)
{
	int			x;
	int			y;
	static int	count = 0;

	count++;
	if (count == 1)
	{
		render_map_ini(game);
	}
	else
	{
		y = -1;
		while (++y < game->height)
		{
			x = -1;
			while (++x < game->width)
			{
				if (game->map[y][x] == ENEMIE)
					draw_e(game, x, y);
				if (game->col == 0 && game->map[y][x] == EXIT)
					render_exit(game, x, y);
			}
		}
	}
}
