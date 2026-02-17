/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_extra_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:11:34 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/25 09:18:44 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long_bonus.h"

void	move_enemies(t_game *game)
{
	t_enemy	*en;
	t_enemy	*head;

	en = game->enemy;
	head = game->enemy;
	while (en)
	{
		if (game->map[en->enemy_y][en->enemy_x] == ENEMIE)
			move_enemy(game, en);
		game->enemy = game->enemy->next;
		en = en->next;
		render_map(game);
	}
	game->enemy = head;
}

void	updtae_animations(void *param)
{
	t_game		*game;
	static int	i = 0;
	static int	c = 0;

	i++;
	game = (t_game *)param;
	player_animation(game);
	if (i % 100 == 0)
	{
		c++;
		move_enemies(game);
	}
}
