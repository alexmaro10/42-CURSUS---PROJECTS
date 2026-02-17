/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:11:23 by almaldon          #+#    #+#             */
/*   Updated: 2025/12/11 10:26:42 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define LIMIT_PHILO 200
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	int				used;
	pthread_mutex_t	block;
}	t_fork;

typedef struct s_times
{
	pthread_mutex_t	console_mutex;
	pthread_mutex_t	m_is_dead;
	pthread_t		death_thread;
	long			start_time;
	int				num;
	int				die;
	int				eat;
	int				sleep;
	int				meal_max;
	int				is_dead;
}	t_times;

typedef struct s_philo
{
	pthread_mutex_t	m_last_meal;
	pthread_t		thread;
	t_times			*times;
	t_fork			*r_fork;
	t_fork			*l_fork;
	long			last_meal;
	int				pos;
	int				meal_count;
	int				r_fork_t;
	int				l_fork_t;
	int				finished_eating;
}	t_philo;

//MAIN.C

void	init_philos(t_philo *philos, t_fork *forks, t_times *times, int index);
int		create_philos(t_philo **philos, t_fork **forks, t_times *times);
int		init_times(t_times *times, int argc, char **argv);
int		free_all(t_philo *philos, t_fork *forks, int exit_code);

//UTILS.C

void	ft_usleep(long int time_in_ms);
void	log_action(char *str, t_philo *philos);
long	ft_gettime(void);

//CHECK_ARG.C
int		check_arg(int argc, char **argv);

//THREADS.C

int		create_threads(t_philo **philos, t_times *times);
int		wait_threads(t_philo **philos, t_times *times);
void	*routine(void *arg);

//FORKS.C

void	take_fork(char fork_name, t_philo *philos);
void	release_fork(char fork_name, t_philo *philos);
void	release_forks_and_sleep(t_philo *philos);

//DEATH.C

int		is_dead(t_philo *phil);
int		stop_threads(t_philo *phil);
int		check_philo_death(t_philo *phil, long index_time);
void	*check_philos_death(void *arg);
int		is_digit(char *c);

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);

#endif