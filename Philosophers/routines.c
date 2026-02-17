/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:51:21 by almaldon          #+#    #+#             */
/*   Updated: 2025/12/11 11:12:06 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo **philos, t_times *times)
{
	int	index;

	times->start_time = ft_gettime();
	index = -1;
	while (++index < times->num)
	{
		if (pthread_create(&((*philos)[index].thread), NULL, routine,
			&((*philos)[index])))
			return (0);
	}
	if (pthread_create(&(times->death_thread), NULL,
			check_philos_death, philos))
		return (0);
	return (1);
}

int	wait_threads(t_philo **philos, t_times *times)
{
	int	index;
	int	return_code;

	index = -1;
	return_code = 1;
	while (++index < times->num)
	{
		if (pthread_join((*philos)[index].thread, NULL))
			return_code = 0;
	}
	if (pthread_join(times->death_thread, NULL))
		return_code = 0;
	return (return_code);
}

static void	eat_cycle(t_philo *philos)
{
	take_fork('l', philos);
	if (is_dead(philos))
		return ;
	if (philos->l_fork_t)
		take_fork('r', philos);
	if (is_dead(philos))
		return ;
	if (philos->l_fork_t && philos->r_fork_t)
	{
		pthread_mutex_lock(&(philos->m_last_meal));
		philos->last_meal = ft_gettime() - philos->times->start_time;
		pthread_mutex_unlock(&(philos->m_last_meal));
		log_action("is eating", philos);
		ft_usleep(philos->times->eat);
		philos->meal_count++;
		release_forks_and_sleep(philos);
	}
}

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->pos % 2 != 0)
		ft_usleep(philos->times->eat);
	while (!is_dead(philos))
	{
		if (philos->meal_count >= philos->times->meal_max
			&& philos->times->meal_max > 0)
		{
			pthread_mutex_lock(&(philos->m_last_meal));
			philos->last_meal = ft_gettime() - philos->times->start_time;
			pthread_mutex_unlock(&(philos->m_last_meal));
			philos->finished_eating = 1;
			break ;
		}
		eat_cycle(philos);
	}
	return (NULL);
}
