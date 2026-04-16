/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:49:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:00:55 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	end_with_map(char **map, t_map_data *map_data)
{
	int	m;
	int	i;

	i = 0;
	m = 0;
	while (map[i])
		i++;
	i--;
	if (map[i][ft_strlen(map[i]) - 1] == '\n')
		return (1);
	i = -1;
	while (map[++i])
	{
		if (map[i][0] && (map[i][0] == '1' || map[i][0] == ' ')
			&& ft_strlen(map[i]) > 1 && m == 0)
		{
			m = 1;
			map_data->map_init_line = i;
		}
		if (m == 1 && map[i][0] && (map[i][0] != '1' && map[i][0] != ' '))
			return (1);
	}
	return (0);
}

static int	validate_rgb(char **colours)
{
	int	i;
	int	n;
	int	x;
	int	digit;

	i = -1;
	while (++i < 3)
	{
		x = 0;
		digit = 0;
		while (colours[i][x])
		{
			if (ft_isdigit(colours[i][x]))
				digit++;
			x++;
		}
		if (digit > 3)
			return (1);
		n = ft_atoi(colours[i]);
		if (n < 0 || n > 255)
			return (1);
	}
	return (0);
}

static int	colours_validation(char **map, t_map_data *map_data)
{
	char	**coloursc;
	char	**coloursf;

	if (extract_colours_f(map, map_data) != 0
		|| extract_colours_c(map, map_data) != 0)
		return (1);
	coloursc = ft_split(map_data->c, ',');
	coloursf = ft_split(map_data->f, ',');
	if (!coloursc || !coloursc[0] || !coloursc[1] || !coloursc[2]
		|| !coloursf || !coloursf[0] || !coloursf[1] || !coloursf[2])
	{
		ft_free_map(map);
		ft_free_struct(map_data);
		return (1);
	}
	if (validate_rgb(coloursc) || validate_rgb(coloursf))
	{
		ft_free_map(coloursc);
		ft_free_map(coloursf);
		return (1);
	}
	ft_free_map(coloursc);
	ft_free_map(coloursf);
	return (0);
}

static int	only_allowed_tokens_in_map(char **map, t_map_data *map_data)
{
	int	i;
	int	j;

	if (valid_spaces(map, map_data) != 0)
		return (1);
	i = map_data->map_init_line - 1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'D')
			{
				if (is_zero_sorrounded(map, i, j, map_data) != 0)
					return (1);
			}
			else if (map[i][j] != '\n' && map[i][j] != '1' && map[i][j] != ' ')
				return (1);
			j++;
		}
	}
	return (0);
}

int	valid_map(char **map, t_map_data *map_data)
{
	int	ret;

	ret = exist_token(map, map_data);
	if (ret != 0)
	{
		if (ret == 1)
			return (ft_exit(1, "Can't found some tokens in map."));
		if (ret == 2)
			return (ft_exit(1, "Duplicate token found in map."));
	}
	if (end_with_map(map, map_data) != 0)
		return (ft_exit(1, "Map must be at the end of the file."));
	if (colours_validation(map, map_data) != 0)
		return (ft_exit(1, "The values of field F/C must be between 0 - 255."));
	if (surrounded_map(map, map_data) != 0)
		return (ft_exit(1, "The map is not surrounded with 1's."));
	if (not_void(map, map_data) != 0)
		return (ft_exit(1, "The map is not surrounded with 1'sa."));
	if (only_allowed_tokens_in_map(map, map_data) != 0)
		return (ft_exit(1, "Forbidden token founded on the map."));
	if (only_one_player(map, map_data) != 0)
		return (ft_exit(1, "The number of player's character must be 1."));
	return (0);
}
