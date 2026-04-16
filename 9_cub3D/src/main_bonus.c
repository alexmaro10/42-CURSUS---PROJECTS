/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:36 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:01:27 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_game(t_game *game)
{
	ft_free_map(game->map);
	ft_free_struct(&game->map_data);
}

int	check_texture_files_open(t_map_data *map_data)
{
	int	fd[4];

	fd[0] = open(map_data->no, O_RDONLY);
	fd[1] = open(map_data->so, O_RDONLY);
	fd[2] = open(map_data->we, O_RDONLY);
	fd[3] = open(map_data->ea, O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0)
	{
		printf(RED "ERROR\nFailed to load textures.\n" RESET);
		return (1);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (0);
}

int	init_all_data(t_game *game, char *filename, int argc)
{
	init_map_data(&game->map_data);
	if (check_args(filename, argc) != 0)
		return (1);
	game->map = file_to_charpp(filename);
	if (!game->map)
		return (1);
	if (valid_map(game->map, &game->map_data) != 0)
	{
		ft_free_map(game->map);
		ft_free_struct(&game->map_data);
		return (EXIT_FAILURE);
	}
	game->map_data.only_map = extract_map(game->map,
			game->map_data.map_init_line);
	if (fill_structures(game->map, &game->map_data) != 0
		|| check_texture_files_open(&game->map_data) == 1)
	{
		ft_free_map(game->map);
		ft_free_struct(&game->map_data);
		return (EXIT_FAILURE);
	}
	init_player_keys(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_all_data(&game, argv[1], argc) == 1)
		return (1);
	if (init_mlx(&game) != 0)
		return (EXIT_FAILURE);
	if (load_texture(game.mlx.mlx, &game.north, game.map_data.no)
		|| load_texture(game.mlx.mlx, &game.south, game.map_data.so)
		|| load_texture(game.mlx.mlx, &game.west, game.map_data.we)
		|| load_texture(game.mlx.mlx, &game.east, game.map_data.ea)
		|| load_texture(game.mlx.mlx, &game.door, game.map_data.d))
		return (EXIT_FAILURE);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx.win, 17, 0, close_game, &game);
	mlx_hook(game.mlx.win, 6, 1L << 6, mouse_move, &game);
	mlx_mouse_move(game.mlx.mlx, game.mlx.win, WIN_W / 2, WIN_H / 2);
	mlx_loop_hook(game.mlx.mlx, game_loop, &game);
	mlx_loop(game.mlx.mlx);
	free_game(&game);
	return (0);
}
