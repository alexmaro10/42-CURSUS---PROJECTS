/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:24:42 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:02:58 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	init_line(t_line *line, t_point p1, t_point p2)
{
	line->dx = abs(p2.x - p1.x);
	line->dy = -abs(p2.y - p1.y);
	line->sx = -1;
	line->sy = -1;
	if (p1.x < p2.x)
		line->sx = 1;
	if (p1.y < p2.y)
		line->sy = 1;
	line->err = line->dx + line->dy;
}

static void	draw_line(t_mlx *mlx, t_point p1, t_point p2, int color)
{
	t_line	line;

	init_line(&line, p1, p2);
	while (1)
	{
		my_mlx_pixel_put(mlx, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			p1.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			p1.y += line.sy;
		}
	}
}

static void	get_triangle_points(t_player *player, int px, int py, t_triangle *t)
{
	t->p1.x = px + (int)(player->dir_x * (MINIMAP_SCALE / 2));
	t->p1.y = py + (int)(player->dir_y * (MINIMAP_SCALE / 2));
	t->p2.x = px + (int)(-player->dir_y * (MINIMAP_SCALE / 2) / 2);
	t->p2.y = py + (int)(player->dir_x * (MINIMAP_SCALE / 2) / 2);
	t->p3.x = px - (int)(-player->dir_y * (MINIMAP_SCALE / 2) / 2);
	t->p3.y = py - (int)(player->dir_x * (MINIMAP_SCALE / 2) / 2);
}

static void	draw_triangle(t_mlx *mlx, t_triangle *t, int color)
{
	draw_line(mlx, t->p1, t->p2, color);
	draw_line(mlx, t->p2, t->p3, color);
	draw_line(mlx, t->p3, t->p1, color);
}

void	draw_player_triangle(t_game *game)
{
	int			px;
	int			py;
	int			size;
	t_triangle	t;

	px = MINIMAP_OFFSET_X + (int)(game->player.pos_x * MINIMAP_SCALE);
	py = MINIMAP_OFFSET_Y + (int)(game->player.pos_y * MINIMAP_SCALE);
	size = MINIMAP_SCALE / 2;
	get_triangle_points(&game->player, px, py, &t);
	draw_triangle(&game->mlx, &t, 0xFF0000);
}
