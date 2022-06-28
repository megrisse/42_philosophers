/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:52:57 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 14:35:30 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	optimise(int ac, char **av)
{
	int	i;

	i = 1;
	while (i++ < ac)
		if (ft_atoi(av[i]) < 0)
			return (ERROR);
	return (SUCCES);
}

int	main(int ac, char **av)
{
	t_infos	infos;

	infos.die = 1;
	memset(&infos, 0, sizeof(infos));
	if (ac > 5)
		print_error("TOO FEW ARGUMENTS\n");
	if (optimise(ac, av))
		print_error("WRONG ARGUMENTS");
	if (initialize(&infos, ac, av))
		return (ERROR);
	
}
