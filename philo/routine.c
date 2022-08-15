/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:59 by megrisse          #+#    #+#             */
/*   Updated: 2022/08/15 03:06:44 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_routine(t_philo *philo, char *str, int key)
{
    pthread_mutex_lock(&philo->args->print);
	printf("%lld\t%d\t%s\n", (get_time() - philo->args->creation_time) / 1000
    , philo->index, str);
    if (key == 0)
        pthread_mutex_unlock(&philo->args->print);
}

int dead_of_philo(t_philo **philo)
{
    t_philo *ptr;
    int     i;

    i = 0;
    ptr = *philo;
    ft_usleep((ptr->args->time_to_die / 2) * 1000);
    while(1)
    {
        if (ptr->finish == 0 && get_time() - ptr->last_meal > ptr->args->time_to_die * 1000)
            return (print_routine(ptr, "is dead", 1), ERROR);
        if (ptr->finish == 1)
        {
            i++;
            //ptr->finish++;
        }
        if (i == ptr->args->must_eat_each)
            break ;
    }
    ft_usleep(ptr->args->time_to_die * 1000);
    return (SUCCES);
}