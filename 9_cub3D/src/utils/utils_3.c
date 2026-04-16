/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:25:13 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 08:41:29 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	extract_ea(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	x;

	i = map_data->ea_line;
	j = 3;
	while (map[i][j] && map[i][j] == ' ')
	{
		j++;
	}
	map_data->ea = ft_calloc(ft_strlen(map[i]) - j + 1, sizeof(char));
	if (!map_data->ea)
		return (1);
	x = 0;
	while (map[i][j])
	{
		map_data->ea[x] = map[i][j];
		j++;
		x++;
	}
	map_data->ea[x - 1] = '\0';
	return (0);
}

int	extract_colours_c(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	x;

	i = map_data->c_line;
	j = 2;
	while (map[i][j] && map[i][j] == ' ')
	{
		j++;
	}
	map_data->c = ft_calloc(ft_strlen(map[i]) - j + 1, sizeof(char));
	if (!map_data->c)
		return (1);
	x = 0;
	while (map[i][j])
	{
		map_data->c[x] = map[i][j];
		j++;
		x++;
	}
	return (0);
}

char	*ft_strdup_no_nl(const char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		len--;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

int	rgb_to_int(char *colors)
{
	int		r;
	int		g;
	int		b;
	char	**c;

	c = ft_split(colors, ',');
	r = ft_atoi(c[0]);
	g = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	ft_free_map(c);
	return ((r << 16) | (g << 8) | b);
}
