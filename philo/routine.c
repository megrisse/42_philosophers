/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:59 by megrisse          #+#    #+#             */
/*   Updated: 2022/08/19 01:18:30 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(t_philo *philo, char *str, int key)
{
	pthread_mutex_lock(&philo->args->print);
	printf("%lld\t%d\t%s\n", get_time() - philo->args->creation_time,
		philo->index, str);
	if (key == 0)
		pthread_mutex_unlock(&philo->args->print);
}

int	change_last_meal(t_philo **philo, int key)
{
	t_philo	*ptr;

	ptr = *philo;
	pthread_mutex_lock(&ptr->args->time);
	if (key == 0)
		return ((*philo)->last_meal = get_time(), SUCCES);
	else if (key == 1)
	{
		if (get_time() - ptr->last_meal
			> ptr->args->time_to_die)
			return (ERROR);
	}
	pthread_mutex_unlock(&ptr->args->time);
	return (SUCCES);
}

int	dead_of_philo(t_philo **philo)
{
	t_philo	*ptr;
	int		i;

	i = 0;
	ptr = *philo;
	ft_usleep(ptr->args->time_to_die);
	while (1)
	{
		if (ptr->finish == 0
			&& change_last_meal(philo, 1) != SUCCES && ptr->is_die == 0)
			return (print_routine(ptr, "is dead", 1), ERROR);
		if (ptr->finish == 1)
			i++;
		if (i == ptr->args->must_eat_each)
			break ;
		ptr = ptr->next;
	}
	return (SUCCES);
}
