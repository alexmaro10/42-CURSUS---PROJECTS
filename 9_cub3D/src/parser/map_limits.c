/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:43:20 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/08 10:28:36 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	first_line_map(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] && map[i][j] == ' ')
		j++;
	while (map[i][j + 1])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

static int	last_line_map(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] && map[i][j] == ' ')
		j++;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

static int	middle_lines_map(char **map, int i)
{
	int	j;
	int	len;

	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len < 2)
			continue ;
		j = 0;
		while (j + 1 < len - 1 && map[i][j] == ' ')
			j++;
		if (j + 1 < len - 1 && map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		j = len - 2;
		if (j >= 0 && j < len - 1 && map[i][j] != '1' && map[i][j] != ' ')
			return (1);
	}
	return (0);
}

int	surrounded_map(char **map, t_map_data *map_data)
{
	int	i;

	i = map_data->map_init_line;
	if (first_line_map(map, i) == 1)
		return (1);
	i++;
	if (middle_lines_map(map, i) == 1)
		return (1);
	while (map[i])
		i++;
	i--;
	if (last_line_map(map, i) == 1)
		return (1);
	return (0);
}
