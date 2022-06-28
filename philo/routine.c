/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:34:18 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 17:42:23 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	taking_forks(t_philo *philos)
{
	pthread_mutex_lock(philos->right);
	print_routine(philos, "has taken a fork");
	pthread_mutex_lock(philos->left);
	print_routine(philos, "has taken a fork");
}

static void	eating(t_philo *philos)
{
	long long	ms;

	pthread_mutex_lock(&philos->check_mutex);
	gettimeofday(&philos->last_meal, NULL);
	ms = time_in_ms(philos->last_meal) - \
		time_in_ms(philos->infos->creation_time);
	pthread_mutex_lock(&philos->infos->mutex);
	if (!philos->infos->finish)
		printf("%lld\t%d\t%s\n", ms, philos->num + 1, "is eating");
	philos->num_of_eat += 1;
	if (philos->num_of_eat == philos->infos->must_eat_each)
		philos->infos->sated += 1;
	pthread_mutex_unlock(&philos->infos->mutex);
	usleep(philos->infos->time_to_eat * 1000);
	pthread_mutex_unlock(philos->right);
	pthread_mutex_unlock(philos->left);
	pthread_mutex_unlock(&philos->check_mutex);
}

static void	sleeping(t_philo *philos)
{
	print_routine(philos, "is sleeping");
	usleep(philos->infos->time_to_sleep * 1000);
}

static void	thinking(t_philo *philos)
{
	print_routine(philos, "is thinking");
}

void	*routine(void *av)
{
	t_philo	*philos;

	philos = av;
	if (philos->num % 2 == 0)
		usleep(philos->infos->time_to_eat * 1000);
	while (!philos->infos->finish)
	{
		taking_forks(philos);
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return (NULL);
}