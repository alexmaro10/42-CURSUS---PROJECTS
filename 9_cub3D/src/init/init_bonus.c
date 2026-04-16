/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:42:40 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:00:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_player_keys(t_game *game)
{
	double	fov;

	fov = FOV_VALUE * M_PI / 180.0;
	game->player.pos_x = game->map_data.player_data.x + 0.5;
	game->player.pos_y = game->map_data.player_data.y + 0.5;
	if (game->map_data.player_data.dir == 'N')
		game->player.angle = M_PI * 1.5;
	else if (game->map_data.player_data.dir == 'S')
		game->player.angle = M_PI / 2;
	else if (game->map_data.player_data.dir == 'E')
		game->player.angle = 0;
	else if (game->map_data.player_data.dir == 'W')
		game->player.angle = M_PI;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->player.plane_x = -game->player.dir_y * tan(fov / 2);
	game->player.plane_y = game->player.dir_x * tan(fov / 2);
	init_keys(game);
}

void	init_map_data(t_map_data *map_data)
{
	map_data->no = NULL;
	map_data->so = NULL;
	map_data->we = NULL;
	map_data->ea = NULL;
	map_data->f = NULL;
	map_data->c = NULL;
	map_data->d = NULL;
	map_data->only_map = NULL;
}

char	**extract_map(char **file, int map_start)
{
	int		i;
	int		lines;
	char	**map;

	lines = 0;
	i = map_start;
	while (file[i])
	{
		lines++;
		i++;
	}
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = ft_strdup_no_nl(file[map_start + i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	fill_structures(char **map, t_map_data *map_data)
{
	int		i_j[2];
	char	tile;

	i_j[0] = -1;
	if (extract_no(map, map_data) != 0 || extract_so(map, map_data) != 0
		|| extract_we(map, map_data) != 0 || extract_ea(map, map_data) != 0
		|| extract_d(map, map_data))
		return (1);
	map_data->c_color = rgb_to_int(map_data->c);
	map_data->f_color = rgb_to_int(map_data->f);
	while (map_data->only_map[++i_j[0]])
	{
		i_j[1] = -1;
		while (map_data->only_map[i_j[0]][++i_j[1]])
		{
			tile = map_data->only_map[i_j[0]][i_j[1]];
			if (tile != '0' && tile != '1' && tile != 'D' && tile != ' ')
			{
				map_data->player_data.dir = map_data->only_map[i_j[0]][i_j[1]];
				map_data->player_data.x = i_j[1];
				map_data->player_data.y = i_j[0];
			}
		}
	}
	return (0);
}

int	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (1);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_W, WIN_H, "cub3D");
	if (!game->mlx.win)
		return (1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_W, WIN_H);
	if (!game->mlx.img)
		return (1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img,
			&game->mlx.bpp,
			&game->mlx.line_len,
			&game->mlx.endian);
	return (0);
}
