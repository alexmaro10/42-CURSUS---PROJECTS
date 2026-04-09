/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:54:23 by almaldon          #+#    #+#             */
/*   Updated: 2025/08/02 09:05:14 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long.h"

static void	start_game(char *map, t_game *game)
{
	game->map = read_map(map);
	game->height = ft_count_rows(game->map);
	game->width = ft_strlen(game->map[0]);
	coord_player(game->map, &game->player_x, &game->player_y);
	n_collect(game->map, &game->collectibles);
	if (!filter_map(*game))
	{
		free_map(game->map);
		ft_error("Invalid format map.");
	}
	init_game(game);
	if (!load_textures(game))
	{
		mlx_terminate(game->mlx);
		free_map(game->map);
		ft_error("Loading textures failed!");
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_error("Invalid arguments, use only one map.");
	}
	if (check_extension(argv[1]) == 0)
		ft_error("Invalid type argument, use a '.ber' type argument.");
	start_game(argv[1], &game);
	render_map(&game);
	mlx_key_hook(game.mlx, handle_input, &game);
	mlx_close_hook(game.mlx, (void *)close_game, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map);
	return (0);
}
