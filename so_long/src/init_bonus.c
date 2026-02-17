/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:20:59 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/26 08:48:42 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->width * TILE_SIZE,
			(game->height + 2) * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		ft_error("Initializing MLX failed!");
	game->moves = 0;
}

bool	load_tex(mlx_t *mlx, mlx_image_t **img, const char *path)
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

static bool	load_textures2(t_game *game)
{
	if (!load_tex(game->mlx, &game->images.img_player_r,
			"assets/player_r_f0.png") || !load_tex(game->mlx,
			&game->images.img_player_l, "assets/player_l_f0.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_0, "assets/0.png")
		|| !load_tex(game->mlx, &game->images.img_1, "assets/1.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_2, "assets/2.png")
		|| !load_tex(game->mlx, &game->images.img_3, "assets/3.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_4, "assets/4.png")
		|| !load_tex(game->mlx, &game->images.img_5, "assets/5.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_6, "assets/6.png")
		|| !load_tex(game->mlx, &game->images.img_7, "assets/7.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_8, "assets/8.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_9, "assets/9.png")
		|| !load_tex(game->mlx, &game->images.img_exit_o, "assets/exit_o.png"))
		return (false);
	game->images.img_player_current = game->images.img_player_l;
	game->player.dir = -1;
	return (true);
}

bool	load_textures(t_game *game)
{
	if (!load_tex(game->mlx, &game->images.img_player_l_f1,
			"assets/player_l_f1.png") || !load_tex(game->mlx,
			&game->images.img_player_r_f1, "assets/player_r_f1.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_player_r_s,
			"assets/player_rs_f0.png") || !load_tex(game->mlx,
			&game->images.img_player_l_s, "assets/player_ls_f0.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_player_rs_f1,
			"assets/player_rs_f1.png") || !load_tex(game->mlx,
			&game->images.img_player_ls_f1, "assets/player_ls_f1.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_collect,
			"assets/collect.png") || !load_tex(game->mlx,
			&game->images.img_floor, "assets/floor.png"))
		return (false);
	if (!load_tex(game->mlx, &game->images.img_wall,
			"assets/wall.png") || !load_tex(game->mlx,
			&game->images.img_exit,
			"assets/exit.png") || !load_tex(game->mlx,
			&game->images.img_enemy, "assets/enemy.png"))
		return (false);
	return (load_textures2(game));
}
