/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:51:54 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 14:27:48 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_args(t_infos infos, int ac, char **av)
{
	infos.philos_num = ft_atoi(av[1]);
	infos.time_to_die = ft_atoi(av[2]);
	infos.time_to_eat = ft_atoi(av[3]);
	infos.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		infos.must_eat_each = ft_atoi(av[5]);
}

static int	check_args(t_infos infos, int ac)
{
	if (ac == 6 && infos.must_eat_each <= 0)
		return (print_error("Wrong number of must eat each\n"));
	else if (infos.philos_num < 0)
		return (print_error("Wrong number of philos\n"));
	else if (infos.time_to_die < 0)
		return (print_error("Wrong time to die\n"));
	else if (infos.time_to_eat < 0)
		return (print_error("Wrong time to eat\n"));
	else if (infos.time_to_sleep < 0)
		return (print_error("Wrong time to sleep\n"));
	else
		return (SUCCES);
}

static int	init_philos(t_infos *infos)
{
	int	i;

	pthread_mutex_init(infos->mutex, NULL);
	if (ft_alloc(&infos->philos, sizeof(t_philo) * infos->philos_num) || \
		ft_alloc(&infos->forks, sizeof(pthread_mutex_t) * infos->philos_num))
		return (print_error("ALLOCATION ERROR"));
	i = 0;
	while (i < infos->philos_num)
	{
		infos->philos[i].num = i;
		pthread_mutex_init(infos->forks[i], NULL);
		pthread_mutex_init(infos->philos[i].check_mutex, NULL);
		if (i == 0)
			infos->philos[i].left = &infos->forks[infos->philos_num - 1];
		else
		infos->philos[i].left = &infos->forks[i - 1];
		infos->philos[i].right = &infos->finish[i];
		infos->philos[i].infos = infos;
		++i;
	}
	return (SUCCES);
}

int	initialize(t_infos *infos, int ac, char **av)
{
	get_args(infos, ac, av);
	if (check_args(infos, ac))
		return (ERROR);
	if (init_philos(infos))
		return (ERROR);
	return (SUCCES);
}
