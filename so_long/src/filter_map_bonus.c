/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:00:21 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/27 10:50:32 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

int	check_map_char(char	**map)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'C'
				&& c != 'E' && c != 'P' && c != 'D')
				return (0);
		}
	}
	return (1);
}

int	rect_map(char **map, int rows, int colm)
{
	int	i;
	int	j;
	int	count_c;

	i = -1;
	if (rows == colm)
		return (0);
	while (map[++i])
	{
		j = -1;
		count_c = 0;
		while (map[i][++j])
			count_c++;
		if (count_c != colm)
			return (0);
	}
	return (1);
}

static int	wall_borders_r(char **map, int rows)
{
	int		r;
	int		c;
	int		count;
	char	car;

	count = 0;
	r = 0;
	while (count < 2)
	{
		c = 0;
		while (map[r][c])
		{
			car = map[r][c];
			if (map[r][c] != '1')
				return (0);
			c++;
		}
		count++;
		r = rows - 1;
	}
	return (1);
}

static int	wall_borders_c(char **map, int colm)
{
	int		r;
	int		c;
	int		count;
	char	car;

	count = 0;
	c = 0;
	while (count < 2)
	{
		r = 0;
		while (map[r] && map[r][c])
		{
			car = map[r][c];
			if (map[r][c] != '1')
				return (0);
			r++;
		}
		count++;
		c = colm - 1;
	}
	return (1);
}

int	wall_borders(char **map, int rows, int colm)
{
	if (!wall_borders_r(map, rows) || !wall_borders_c(map, colm))
		return (0);
	return (1);
}
