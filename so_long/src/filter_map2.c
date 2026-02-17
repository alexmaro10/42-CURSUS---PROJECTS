/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:24:35 by almaldon          #+#    #+#             */
/*   Updated: 2025/08/02 09:26:50 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long.h"

void	flood_fill(int x, int y, t_state *state, char **map)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	else if (map[y][x] == 'C')
		state->collect++;
	else if (map[y][x] == 'E')
		state->exit_reachable++;
	map[y][x] = 'V';
	flood_fill (x + 1, y, state, map);
	flood_fill (x - 1, y, state, map);
	flood_fill (x, y + 1, state, map);
	flood_fill (x, y - 1, state, map);
}

int	req_min_map(char **map)
{
	int	count_e_p_c[3];
	int	i;
	int	j;

	count_e_p_c[0] = 0;
	count_e_p_c[1] = 0;
	count_e_p_c[2] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				count_e_p_c[0]++;
			if (map[i][j] == 'P')
				count_e_p_c[1]++;
			if (map[i][j] == 'C')
				count_e_p_c[2]++;
		}
	}
	if (count_e_p_c[2] >= 1 && count_e_p_c[1] == 1 && count_e_p_c[0] == 1)
		return (1);
	return (0);
}

int	check_extension(char *map_name)
{
	size_t	i;
	size_t	x;
	int		count;

	count = 0;
	i = -1;
	if (!ft_strnstr(map_name, ".ber", ft_strlen(map_name)))
		return (0);
	while (map_name[++i])
	{
		if (map_name[i] == '.')
		{
			count++;
			x = i;
		}
	}
	if (count != 1)
		return (0);
	if ((i - 1) > (x + 3))
		return (0);
	return (1);
}

int	filter_map(t_game game)
{
	t_state	state;
	char	**map_copy;

	state.collect = 0;
	state.exit_reachable = 0;
	if (!check_map_char(game.map))
		return (0);
	if (!rect_map(game.map, game.height, game.width))
		return (0);
	if (!wall_borders(game.map, game.height, game.width))
		return (0);
	if (!req_min_map(game.map))
		return (0);
	map_copy = copy_map(game.map);
	flood_fill(game.player_x, game.player_y, &state, map_copy);
	free_map(map_copy);
	if (state.collect != game.collectibles || state.exit_reachable != 1)
		return (0);
	return (1);
}
