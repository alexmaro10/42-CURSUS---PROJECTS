/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:42:40 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/03 09:46:07 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

void	init_map_data(t_map_data *map_data)
{
	map_data->no = NULL;
	map_data->so = NULL;
	map_data->we = NULL;
	map_data->ea = NULL;
	map_data->f = NULL;
	map_data->c = NULL;
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
	int	i;
	int	j;

	i = -1;
	if (extract_no(map, map_data) != 0 || extract_so(map, map_data) != 0
		|| extract_we(map, map_data) != 0 || extract_ea(map, map_data) != 0)
		return (1);
	map_data->c_color = rgb_to_int(map_data->c);
	map_data->f_color = rgb_to_int(map_data->f);
	while (map_data->only_map[++i])
	{
		j = -1;
		while (map_data->only_map[i][++j])
		{
			if (map_data->only_map[i][j] != '0' &&
				map_data->only_map[i][j] != '1' &&
				map_data->only_map[i][j] != ' ')
			{
				map_data->player_data.dir = map_data->only_map[i][j];
				map_data->player_data.x = j;
				map_data->player_data.y = i;
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
