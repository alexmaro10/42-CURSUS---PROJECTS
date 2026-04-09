/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:34:27 by almaldon          #+#    #+#             */
/*   Updated: 2025/12/11 10:57:46 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_philos_finished(t_philo **philos, t_times *times)
{
	int	i;

	i = -1;
	while (++i < times->num)
	{
		if (!(*philos)[i].finished_eating)
			return (0);
	}
	return (1);
}

int	is_dead(t_philo *phil)
{
	int	alive;

	pthread_mutex_lock(&(phil->times->m_is_dead));
	alive = phil->times->is_dead;
	pthread_mutex_unlock(&(phil->times->m_is_dead));
	return (alive);
}

int	stop_threads(t_philo *phil)
{
	pthread_mutex_lock(&(phil->times->m_is_dead));
	phil->times->is_dead = 1;
	pthread_mutex_unlock(&(phil->times->m_is_dead));
	return (EXIT_FAILURE);
}

int	check_philo_death(t_philo *phil, long index_time)
{
	int	dead;
	int	last_meal;

	dead = 0;
	if (phil->finished_eating)
		return (0);
	pthread_mutex_lock(&(phil->m_last_meal));
	last_meal = index_time - phil->last_meal;
	pthread_mutex_unlock(&(phil->m_last_meal));
	if (last_meal > phil->times->die)
	{
		pthread_mutex_lock(&(phil->times->console_mutex));
		pthread_mutex_lock(&(phil->times->m_is_dead));
		phil->times->is_dead = 1;
		pthread_mutex_unlock(&(phil->times->m_is_dead));
		printf("\033[1;31m[%05ld] Philosopher %d died\033[0m\n",
			index_time, phil->pos + 1);
		pthread_mutex_unlock(&(phil->times->console_mutex));
		dead = 1;
	}
	return (dead);
}

void	*check_philos_death(void *arg)
{
	t_times	*params;
	t_philo	**philos;
	long	index_time;
	int		index;

	philos = (t_philo **)arg;
	params = philos[0]->times;
	while (1)
	{
		index_time = ft_gettime() - params->start_time;
		index = -1;
		while (++index < params->num)
			if (check_philo_death(&(*philos)[index], index_time))
				return (NULL);
		if (all_philos_finished(philos, params))
		{
			pthread_mutex_lock(&(params->m_is_dead));
			params->is_dead = 1;
			pthread_mutex_unlock(&(params->m_is_dead));
			return (NULL);
		}
		ft_usleep(1);
	}
	return (NULL);
}
