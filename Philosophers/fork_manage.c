/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:19:01 by almaldon          #+#    #+#             */
/*   Updated: 2025/12/11 11:01:18 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_fork_info(char f_name, t_philo *philos, t_fork **f, int **taken)
{
	if (f_name == 'l')
	{
		*taken = &philos->l_fork_t;
		*f = philos->l_fork;
	}
	else
	{
		*taken = &philos->r_fork_t;
		*f = philos->r_fork;
	}
}

// Función para tomar un fork
void	take_fork(char fork_name, t_philo *philos)
{
	int		*taken;
	t_fork	*fork;

	if (!is_dead(philos))
	{
		get_fork_info(fork_name, philos, &fork, &taken);
		while (!is_dead(philos))
		{
			pthread_mutex_lock(&(fork->block));
			if (!fork->used)
			{
				fork->used = 1;
				*taken = 1;
				pthread_mutex_unlock(&(fork->block));
				log_action("has taken a fork", philos);
				break ;
			}
			pthread_mutex_unlock(&(fork->block));
			usleep(1000);
		}
	}
}

void	release_fork(char fork_name, t_philo *philos)
{
	int		*taken;
	t_fork	*fork;

	taken = &(philos->r_fork_t);
	fork = philos->r_fork;
	if (fork_name == 'l')
	{
		taken = &(philos->l_fork_t);
		fork = philos->l_fork;
	}
	pthread_mutex_lock(&(fork->block));
	*taken = 0;
	fork->used = 0;
	pthread_mutex_unlock(&(fork->block));
}

void	release_forks_and_sleep(t_philo *philos)
{
	if (!is_dead(philos))
	{
		release_fork('r', philos);
		release_fork('l', philos);
		log_action("is sleeping", philos);
		ft_usleep(philos->times->sleep);
		log_action("is thinking", philos);
	}
}
