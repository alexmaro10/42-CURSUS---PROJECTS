/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:25 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/26 07:59:28 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long.h"

static void	sprite_control(int dx, t_game *game)
{
	if (dx == -1)
	{
		game->img_player_current = game->img_player_l;
	}
	else if (dx == 1)
	{
		game->img_player_current = game->img_player_r;
	}
}

static void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	sprite_control(dx, game);
	tile = game->map[new_y][new_x];
	if (tile == WALL)
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (tile == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR;
	}
	if (tile == EXIT && game->collectibles == 0)
	{
		ft_printf("You have won in %d moves!\n", game->moves);
		close_game(game);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	render_map(game);
}

void	close_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	else if (keydata.key == MLX_KEY_W)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_A)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_S)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_D)
		move_player(game, 1, 0);
}
