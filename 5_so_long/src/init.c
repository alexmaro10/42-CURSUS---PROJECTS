/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:20:59 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/27 10:01:19 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->width * TILE_SIZE, game->height * TILE_SIZE,
			"so_long", true);
	if (!game->mlx)
		ft_error("Initializing MLX failed!");
	game->moves = 0;
}

static bool	load_texture(mlx_t *mlx, mlx_image_t **img, const char *path)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(path);
	if (!tex)
		return (false);
	*img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	if (!(*img))
		return (false);
	return (true);
}

bool	load_textures(t_game *game)
{
	if (!load_texture(game->mlx, &game->img_player_r, "assets/player_r.png"))
		return (false);
	if (!load_texture(game->mlx, &game->img_player_l, "assets/player_l.png"))
		return (false);
	if (!load_texture(game->mlx, &game->img_player_current,
			"assets/player_l.png"))
		return (false);
	if (!load_texture(game->mlx, &game->img_collect, "assets/collect.png"))
		return (false);
	if (!load_texture(game->mlx, &game->img_floor, "assets/floor.png"))
		return (false);
	if (!load_texture(game->mlx, &game->img_wall, "assets/wall.png"))
		return (false);
	if (!load_texture(game->mlx, &game->img_exit, "assets/exit.png"))
		return (false);
	return (true);
}
