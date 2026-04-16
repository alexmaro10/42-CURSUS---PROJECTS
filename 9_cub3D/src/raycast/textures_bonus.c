/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:48:14 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:01:05 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	load_texture(void *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (1);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
	return (0);
}

int	get_tex_pixel(t_texture *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_len
			+ x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

//TEXTURES
static void	coord_to_texture(t_ray *ray, t_texture *tex)
{
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= tex->width)
		ray->tex_x = tex->width - 1;
	if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
}

t_texture	*texture_selector(t_game *game, t_ray *ray)
{
	t_texture	*tex;
	double		wall_x;

	if (ray->hit_type == 'D')
		tex = &game->door;
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		tex = &game->west;
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		tex = &game->east;
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		tex = &game->north;
	else
		tex = &game->south;
	if (ray->side == 0)
		wall_x = game->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * tex->width);
	coord_to_texture(ray, tex);
	return (tex);
}

void	draw_textures(t_game *game, int x, t_ray *ray, t_texture *tex)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
		put_pixel(game, x, y++, game->map_data.c_color);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->d = y * 256 - WIN_H * 128 + ray->line_height * 128;
		ray->tex_y = ((ray->d * tex->height) / ray->line_height) / 256;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		if (ray->tex_y >= tex->height)
			ray->tex_y = tex->height - 1;
		ray->color = get_tex_pixel(tex, ray->tex_x, ray->tex_y);
		put_pixel(game, x, y,
			ray->color);
		y++;
	}
	while (y < WIN_H)
		put_pixel(game, x, y++, game->map_data.f_color);
}
