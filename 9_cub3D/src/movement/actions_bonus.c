/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:06:51 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:00:24 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	ray_hit_door(char **map, t_ray *ray)
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
		else if (map[ray->map_y][ray->map_x] == 'P'
			|| map[ray->map_y][ray->map_x] == 'D')
		{
			ray->hit = 1;
			ray->hit_type = map[ray->map_y][ray->map_x];
		}
	}
}

int	mouse_move(int x, int y, t_game *game)
{
	double	speed;

	(void)y;
	speed = 0.00065 * abs(x - (WIN_W / 2));
	if (game->keys.q == 1)
	{
		if (x < WIN_W / 2)
			rot_left(speed, game);
		if (x > WIN_W / 2)
			rot_right(speed, game);
	}
	return (0);
}

void	unlock_door(t_game *game)
{
	t_ray	ray2;
	int		x;

	x = WIN_W / 2;
	init_ray(game, x, &ray2);
	ray_hit_door(game->map_data.only_map, &ray2);
	calculate_perp_distance(game, &ray2);
	if (ray2.hit_type == 'D' && ray2.perp_wall_dist <= 2.5)
	{
		game->map_data.only_map[ray2.map_y][ray2.map_x] = 'P';
	}
}

void	lock_door(t_game *game)
{
	t_ray	ray2;
	int		x;

	x = WIN_W / 2;
	init_ray(game, x, &ray2);
	ray_hit_door(game->map_data.only_map, &ray2);
	calculate_perp_distance(game, &ray2);
	if (ray2.hit_type == 'P' && ray2.perp_wall_dist <= 2.5)
	{
		game->map_data.only_map[ray2.map_y][ray2.map_x] = 'D';
	}
}
