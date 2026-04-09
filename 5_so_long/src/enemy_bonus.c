/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:22:28 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/22 12:02:06 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

static t_enemy	*ft_enemy_new(int x, int y)
{
	t_enemy	*ret;

	ret = malloc(sizeof(t_enemy));
	if (!ret)
		return (0);
	ret->enemy_x = x;
	ret->enemy_y = y;
	ret->next = 0;
	return (ret);
}

static t_enemy	*ft_enemylast(t_enemy *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

static void	ft_enemyadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

	tmp = ft_enemylast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

void	init_enemys(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == ENEMIE)
				ft_enemyadd_back(&game->enemy, ft_enemy_new(x, y));
		}
	}
}

void	free_lst(t_enemy **lst)
{
	t_enemy	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
