/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:00:27 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/26 09:04:33 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long.h"

void	coord_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
		}
	}
}
