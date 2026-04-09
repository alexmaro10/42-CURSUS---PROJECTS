/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:53:59 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/15 14:25:10 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipeline(t_pipeline *pl)
{
	int	i;

	i = -1;
	while (++i < pl->count)
		free_command(&pl->cmds[i]);
	free(pl->cmds);
}

void	ft_free_pipes(int **pipes, int n)
{
	while (n--)
	{
		if (pipes[n])
			free(pipes[n]);
	}
	free(pipes);
}

void	close_all_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
