/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:08:46 by almaldon          #+#    #+#             */
/*   Updated: 2025/12/11 11:07:04 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int time_in_ms)
{
	long	start_time;

	start_time = ft_gettime();
	while ((ft_gettime() - start_time) < time_in_ms)
		usleep(1000);
}

void	log_action(char *str, t_philo *philos)
{
	long	index_time;

	pthread_mutex_lock(&(philos->times->console_mutex));
	if (!is_dead(philos))
	{
		index_time = ft_gettime() - philos->times->start_time;
		printf("\x1b[1;37m[%05ld] Philosopher %d %s\x1b[0m\n",
			index_time, philos->pos + 1, str);
	}
	pthread_mutex_unlock(&(philos->times->console_mutex));
}

long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	is_digit(char *c)
{
	size_t	i;

	if (ft_strlen(c) < 1)
		return (0);
	i = -1;
	while (++i < ft_strlen(c))
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
	}
	return (1);
}
