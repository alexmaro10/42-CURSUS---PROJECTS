/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:42:18 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/15 10:01:10 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	ft_free_struct(t_map_data *map_data)
{
	if (!map_data)
		return ;
	if (map_data->only_map)
		ft_free_map(map_data->only_map);
	if (map_data->no)
		free(map_data->no);
	if (map_data->so)
		free(map_data->so);
	if (map_data->we)
		free(map_data->we);
	if (map_data->ea)
		free(map_data->ea);
	if (map_data->f)
		free(map_data->f);
	if (map_data->c)
		free(map_data->c);
	if (map_data->d)
		free(map_data->d);
}

int	extract_colours_f(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	x;

	i = map_data->f_line;
	j = 2;
	while (map[i][j] && map[i][j] == ' ')
	{
		j++;
	}
	map_data->f = ft_calloc(ft_strlen(map[i]) - j + 1, sizeof(char));
	if (!map_data->f)
		return (1);
	x = 0;
	while (map[i][j])
	{
		map_data->f[x] = map[i][j];
		j++;
		x++;
	}
	return (0);
}

int	extract_no(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	x;

	i = map_data->no_line;
	j = 3;
	while (map[i][j] && map[i][j] == ' ')
	{
		j++;
	}
	map_data->no = ft_calloc(ft_strlen(map[i]) - j, sizeof(char));
	if (!map_data->no)
		return (1);
	x = 0;
	while (map[i][j])
	{
		map_data->no[x] = map[i][j];
		j++;
		x++;
	}
	map_data->no[x - 1] = '\0';
	return (0);
}

int	extract_so(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	x;

	i = map_data->so_line;
	j = 3;
	while (map[i][j] && map[i][j] == ' ')
	{
		j++;
	}
	map_data->so = ft_calloc(ft_strlen(map[i]) - j + 1, sizeof(char));
	if (!map_data->so)
		return (1);
	x = 0;
	while (map[i][j])
	{
		map_data->so[x] = map[i][j];
		j++;
		x++;
	}
	map_data->so[x - 1] = '\0';
	return (0);
}

int	extract_we(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	x;

	i = map_data->we_line;
	j = 3;
	while (map[i][j] && map[i][j] == ' ')
	{
		j++;
	}
	map_data->we = ft_calloc(ft_strlen(map[i]) - j + 1, sizeof(char));
	if (!map_data->we)
		return (1);
	x = 0;
	while (map[i][j])
	{
		map_data->we[x] = map[i][j];
		j++;
		x++;
	}
	map_data->we[x - 1] = '\0';
	return (0);
}
