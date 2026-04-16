/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:10:13 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:02:52 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_square(t_mlx *mlx, int s_x, int s_y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINIMAP_SCALE)
	{
		j = -1;
		while (++j < MINIMAP_SCALE)
			my_mlx_pixel_put(mlx, s_x + i, s_y + j, color);
	}
}

static int	select_color(int y, int x, t_game *game)
{
	if (game->map_data.only_map[y][x] == '1')
		return (0xFFFFFF);
	else if (game->map_data.only_map[y][x] == 'D')
		return (0xAAAA00);
	else if (game->map_data.only_map[y][x] == 'P')
		return (0x00AAAA);
	else
		return (0x000000);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	cell_color;

	y = -1;
	while (game->map_data.only_map[++y])
	{
		x = -1;
		while (game->map_data.only_map[y][++x])
		{
			cell_color = select_color(y, x, game);
			if (game->map_data.only_map[y][x] != ' ')
			{
				draw_square(&game->mlx,
					MINIMAP_OFFSET_X + x * MINIMAP_SCALE,
					MINIMAP_OFFSET_Y + y * MINIMAP_SCALE,
					cell_color);
			}
		}
	}
}
