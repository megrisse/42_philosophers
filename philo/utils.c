/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:40 by megrisse          #+#    #+#             */
/*   Updated: 2022/08/18 16:33:32 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *str)
{
	long	resultat;
	long	signe;
	int		i;

	resultat = 0;
	signe = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	free_philos(t_philo *philos, int x)
{
	t_philo	*ptr;
	int		i;

	ptr = philos;
	i = 0;
	if (x == 1)
		destroy_mutexes(philos);
	if (!philos)
		return ;
	while (1)
	{
		if (i == ptr->args->n_philo - 1)
		{
			free(ptr->args);
			free(ptr);
			return ;
		}
		philos = philos->next;
		free(ptr);
		ptr = philos;
		i++;
	}
}

void	destroy_mutexes(t_philo *philo)
{
	t_philo	*ptr;

	ptr = philo;
	while (ptr->index != ptr->args->n_philo)
	{
		usleep(50);
		pthread_mutex_destroy(&ptr->fork);
		ptr = ptr->next;
	}
	pthread_mutex_destroy(&ptr->fork);
	pthread_mutex_destroy(&philo->args->print);
}
