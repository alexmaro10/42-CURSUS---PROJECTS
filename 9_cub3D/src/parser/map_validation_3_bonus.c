/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:33:25 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:00:51 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	not_void(char **map, t_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = map_data->map_init_line - 1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && map[i + 1]
				&& j < ft_strlen(map[i + 1]))
			{
				if (map[i + 1][j] == '\0')
					return (1);
			}
		}
	}
	return (0);
}

static int	check_token(char *line, char *token, int *n)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (line[i] != token[i])
			return (0);
		i++;
	}
	if (line[i] != ' ' && line[i] != '\0')
		return (0);
	*n = *n + 1;
	return (1);
}

static int	exact_number_tokens(int *counts)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if (counts[i] == 0)
			return (1);
		else if (counts[i] > 1)
			return (2);
	}
	return (0);
}

int	exist_token(char **map, t_map_data *map_data)
{
	int	counts[8];
	int	i;

	i = -1;
	while (++i < 7)
		counts[i] = 0;
	i = -1;
	while (map[++i])
	{
		if (check_token(map[i], "NO", &counts[0]))
			map_data->no_line = i;
		else if (check_token(map[i], "SO", &counts[1]))
			map_data->so_line = i;
		else if (check_token(map[i], "WE", &counts[2]))
			map_data->we_line = i;
		else if (check_token(map[i], "EA", &counts[3]))
			map_data->ea_line = i;
		else if (check_token(map[i], "F", &counts[4]))
			map_data->f_line = i;
		else if (check_token(map[i], "C", &counts[5]))
			map_data->c_line = i;
		else if (check_token(map[i], "DO", &counts[6]))
			map_data->d_line = i;
	}
	return (exact_number_tokens(counts));
}
