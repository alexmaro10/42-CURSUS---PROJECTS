/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:20:15 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/25 09:10:47 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

void	ft_error(const char *msg)
{
	ft_printf("ERROR: %s\n", msg);
	exit(1);
}

void	free_map(char	**map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
	{
		free(map[i]);
	}
	free(map);
}

char	**copy_map(char **map)
{
	int		height;
	int		i;
	char	**new_map;

	height = 0;
	i = -1;
	while (map[height])
		height++;
	new_map = malloc ((height + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	while (++i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
	}
	new_map[height] = NULL;
	return (new_map);
}

char	*ft_strjoin_temp(char *s1, const char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, len1);
	if (s2)
		ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}

int	ft_count_rows(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}
