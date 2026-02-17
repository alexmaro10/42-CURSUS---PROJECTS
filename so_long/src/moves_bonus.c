/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:07:24 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/23 09:51:14 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

static void	rendercount(int p, mlx_image_t *image, t_game *game)
{
	if (p == 1)
	{
		mlx_image_to_window(game->mlx, image,
			2 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
	}
	if (p == 2)
	{
		mlx_image_to_window(game->mlx, game->images.img_0,
			2 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
		mlx_image_to_window(game->mlx, image,
			1 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
	}
	if (p == 3)
	{
		mlx_image_to_window(game->mlx, game->images.img_0,
			2 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->images.img_0,
			1 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
		mlx_image_to_window(game->mlx, image,
			0 * TILE_SIZE, (game->height + 1) * TILE_SIZE);
	}
}

static void	rendercountu(int u, t_game *game)
{
	if (u == 1)
		rendercount(1, game->images.img_1, game);
	if (u == 2)
		rendercount(1, game->images.img_2, game);
	if (u == 3)
		rendercount(1, game->images.img_3, game);
	if (u == 4)
		rendercount(1, game->images.img_4, game);
	if (u == 5)
		rendercount(1, game->images.img_5, game);
	if (u == 6)
		rendercount(1, game->images.img_6, game);
	if (u == 7)
		rendercount(1, game->images.img_7, game);
	if (u == 8)
		rendercount(1, game->images.img_8, game);
	if (u == 9)
		rendercount(1, game->images.img_9, game);
}

static void	rendercountd(int u, t_game *game)
{
	if (u == 1)
		rendercount(2, game->images.img_1, game);
	if (u == 2)
		rendercount(2, game->images.img_2, game);
	if (u == 3)
		rendercount(2, game->images.img_3, game);
	if (u == 4)
		rendercount(2, game->images.img_4, game);
	if (u == 5)
		rendercount(2, game->images.img_5, game);
	if (u == 6)
		rendercount(2, game->images.img_6, game);
	if (u == 7)
		rendercount(2, game->images.img_7, game);
	if (u == 8)
		rendercount(2, game->images.img_8, game);
	if (u == 9)
		rendercount(2, game->images.img_9, game);
}

static void	rendercountc(int u, t_game *game)
{
	if (u == 1)
		rendercount(3, game->images.img_1, game);
	if (u == 2)
		rendercount(3, game->images.img_2, game);
	if (u == 3)
		rendercount(3, game->images.img_3, game);
	if (u == 4)
		rendercount(3, game->images.img_4, game);
	if (u == 5)
		rendercount(3, game->images.img_5, game);
	if (u == 6)
		rendercount(3, game->images.img_6, game);
	if (u == 7)
		rendercount(3, game->images.img_7, game);
	if (u == 8)
		rendercount(3, game->images.img_8, game);
	if (u == 9)
		rendercount(3, game->images.img_9, game);
}

void	update_mov(t_game *game)
{
	static int	u = 0;
	static int	d = 0;
	static int	c = 0;

	u++;
	rendercountu(u, game);
	if (u == 10)
	{
		u = 0;
		d++;
		rendercountd(d, game);
	}
	if (d == 10)
	{
		d = 0;
		u = 0;
		c++;
		rendercountc(c, game);
	}
}
