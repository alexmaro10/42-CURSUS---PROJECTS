/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:10:23 by almaldon          #+#    #+#             */
/*   Updated: 2025/12/11 10:55:20 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philos, t_fork *forks, t_times *times, int index)
{
	philos->times = times;
	philos->pos = index;
	philos->last_meal = 0;
	philos->meal_count = 0;
	philos->r_fork = &forks[index];
	philos->l_fork = &forks[(index + 1) % times->num];
	philos->r_fork_t = 0;
	philos->l_fork_t = 0;
	philos->finished_eating = 0;
	pthread_mutex_init(&(philos->m_last_meal), NULL);
}

int	create_philos(t_philo **philos, t_fork **forks, t_times *times)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * times->num);
	if (!(*philos))
		return (0);
	*forks = malloc(sizeof(t_fork) * times->num);
	if (!(*forks))
	{
		free(*philos);
		return (0);
	}
	i = -1;
	while (++i < times->num)
	{
		(*forks)[i].used = 0;
		pthread_mutex_init(&((*forks)[i].block), NULL);
	}
	i = -1;
	while (++i < times->num)
		init_philos(&(*philos)[i], *forks, times, i);
	return (1);
}

int	init_times(t_times *times, int argc, char **argv)
{
	times->num = ft_atoi(argv[1]);
	times->die = ft_atoi(argv[2]);
	times->eat = ft_atoi(argv[3]);
	times->sleep = ft_atoi(argv[4]);
	times->meal_max = -1;
	if (argc == 6)
		times->meal_max = ft_atoi(argv[5]);
	times->is_dead = 0;
	pthread_mutex_init(&(times->console_mutex), NULL);
	pthread_mutex_init(&(times->m_is_dead), NULL);
	return (1);
}

int	free_all(t_philo *philos, t_fork *forks, int exit_code)
{
	free(philos);
	free(forks);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_times	times;
	t_philo	*philos;
	t_fork	*forks;
	int		return_code;

	return_code = EXIT_SUCCESS;
	if (check_arg(argc, argv) == 0)
	{
		printf("ERROR:\nInvalid Arguments.");
		return (0);
	}
	init_times(&times, argc, argv);
	if (!create_philos(&philos, &forks, &times))
		return (1);
	if (!create_threads(&philos, &times))
		return_code = stop_threads(&philos[0]);
	if (!wait_threads(&philos, &times))
		return (free_all(philos, forks, EXIT_FAILURE));
	return (free_all(philos, forks, return_code));
}
