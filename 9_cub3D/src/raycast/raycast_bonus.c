/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:07:44 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:01:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	ray_hit(char **map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_x < 0 || !map[ray->map_y]
			|| ray->map_x >= (int)ft_strlen(map[ray->map_y]))
			ray->hit = 1;
		else if (map[ray->map_y][ray->map_x] == '1'
			|| map[ray->map_y][ray->map_x] == ' '
			|| map[ray->map_y][ray->map_x] == 'D')
		{
			ray->hit = 1;
			ray->hit_type = map[ray->map_y][ray->map_x];
		}
	}
}

void	calculate_perp_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->perp_wall_dist <= 0.15)
		ray->perp_wall_dist = 0.15;
}

static void	calculate_wall_projection(t_ray *ray)
{
	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}

void	dda_protect(t_game *game, t_ray *ray)
{
	ray_hit(game->map_data.only_map, ray);
	calculate_perp_distance(game, ray);
	calculate_wall_projection(ray);
}

void	raycast(t_game *game)
{
	int			x;
	t_ray		ray;
	t_texture	*tex;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(game, x, &ray);
		dda_protect(game, &ray);
		tex = texture_selector(game, &ray);
		draw_textures(game, x, &ray, tex);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
