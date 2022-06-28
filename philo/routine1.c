/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:58:41 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 17:04:12 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_philos_eat(void *av)
{
	t_infos	*infos;

	infos = av;
	while (!infos->finish)
	{
		pthread_mutex_lock(&infos->mutex);
		if (infos->sated == infos->philos_num)
			infos->finish = 1;
		pthread_mutex_unlock(&infos->mutex);
	}
	return (NULL);
}

void	*check_philo_die(void *av)
{
	t_philo			*philos;
	struct timeval	time;
	long long		ms;

	philos = av;
	while (!philos->infos->finish)
	{
		pthread_mutex_lock(&philos->check_mutex);
		pthread_mutex_lock(&philos->infos->mutex);
		gettimeofday(&time, NULL);
		ms = time_in_ms(time) - time_in_ms(philos->last_meal);
		gettimeofday(&time, NULL);
		if (ms >= philos->infos->time_to_die && philos->infos->finish == 0)
		{
			printf("%lld\t%d\t %s\n", time_in_ms(time) - \
				time_in_ms(philos->infos->creation_time),
				philos->num + 1, "died");
			philos->infos->finish = 1;
		}
		pthread_mutex_unlock(&philos->infos->mutex);
		pthread_mutex_unlock(&philos->check_mutex);
	}
	return (NULL);
}