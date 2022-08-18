/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:18 by megrisse          #+#    #+#             */
/*   Updated: 2022/08/18 20:36:24 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;

	philos = NULL;
	if (ac < 5 || ac > 6)
		return (printf("ARGUMENTS ERROR\n"), ERROR);
	if (inits_philos(&philos, av, ac) != SUCCES)
		return (ERROR);
	philos->n_eating = 0;
	philos->finish = 0;
	philos->last_meal = 0;
	if (init_sim(&philos) != SUCCES)
		return (free_philos(philos, 1), ERROR);
	if (dead_of_philo(&philos) != SUCCES)
		return (free_philos(philos, 1), ERROR);
}
