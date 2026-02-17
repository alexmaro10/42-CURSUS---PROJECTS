/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:10:50 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/26 08:56:54 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

void	free_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->images.img_0);
	mlx_delete_image(game->mlx, game->images.img_1);
	mlx_delete_image(game->mlx, game->images.img_2);
	mlx_delete_image(game->mlx, game->images.img_3);
	mlx_delete_image(game->mlx, game->images.img_4);
	mlx_delete_image(game->mlx, game->images.img_5);
	mlx_delete_image(game->mlx, game->images.img_6);
	mlx_delete_image(game->mlx, game->images.img_7);
	mlx_delete_image(game->mlx, game->images.img_8);
	mlx_delete_image(game->mlx, game->images.img_9);
	mlx_delete_image(game->mlx, game->images.img_player_l);
	mlx_delete_image(game->mlx, game->images.img_player_l_f1);
	mlx_delete_image(game->mlx, game->images.img_player_l_s);
	mlx_delete_image(game->mlx, game->images.img_player_r);
	mlx_delete_image(game->mlx, game->images.img_player_r_f1);
	mlx_delete_image(game->mlx, game->images.img_player_r_s);
	mlx_delete_image(game->mlx, game->images.img_player_rs_f1);
	mlx_delete_image(game->mlx, game->images.img_exit);
	mlx_delete_image(game->mlx, game->images.img_exit_o);
	mlx_delete_image(game->mlx, game->images.img_enemy);
	mlx_delete_image(game->mlx, game->images.img_wall);
	mlx_delete_image(game->mlx, game->images.img_floor);
	mlx_delete_image(game->mlx, game->images.img_collect);
}
