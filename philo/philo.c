/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:52:57 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 17:37:40 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philos(t_infos *infos)
{
	pthread_t	thread;
	int			i;

	gettimeofday(&infos->creation_time, NULL);
	i = 0;
	while (i < infos->philos_num)
	{
		infos->philos[i].last_meal = infos->creation_time;
		pthread_create(&infos->philos[i].thread, NULL,
			routine, &infos->philos[i]);
		pthread_create(&thread, NULL, check_philo_die, &infos->philos[i]);
		pthread_detach(thread);
		++i;
	}
	if (infos->must_eat_each != 0)
	{
		pthread_create(&thread, NULL, check_philos_eat, infos);
		pthread_detach(thread);
		++i;
	}
}

static void	join_hungry_philos(t_infos *infos)
{
	int	i;

	i = 0;
	while (i < infos->philos_num)
	{
		pthread_join(infos->philos[i].thread, NULL);
		pthread_mutex_destroy(&infos->philos[i++].check_mutex);
	}
	free(infos->philos);
	i = 0;
	while (i < infos->philos_num)
		pthread_mutex_destroy(&infos->forks[i++]);
	free(infos->forks);
}

static int	optimise(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (ft_atoi(av[i]) < 0)
			return (ERROR);
	return (SUCCES);
}

int	main(int ac, char **av)
{
	t_infos	infos;

	infos.die = 1;
	memset(&infos, 0, sizeof(infos));
	if (ac != 5 && ac != 6)
		print_error("WRONG ARGUMENTS\n");
	if (optimise(ac, av))
		printf("ERROR\n");
	if (initialize(&infos, ac, av))
		return (ERROR);
	philos(&infos);
	join_hungry_philos(&infos);
	return (0);
}
