/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:53 by megrisse          #+#    #+#             */
/*   Updated: 2022/08/18 23:22:37 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL && i <= 6)
	{
		while (av[i][j] != 0 && av[i][j] >= '0' && av[i][j] <= '9')
			j++;
		if (av[i][j] != 0)
			return (ERROR);
		j = 0;
		i++;
	}
	return (SUCCES);
}

int	protect(t_args *args, int ac)
{
	if (args->n_philo > 200 && args->n_philo <= 0)
		return (ERROR);
	if (args->time_to_die < 60 || args->time_to_eat < 60
		|| args->time_to_sleep < 60)
		return (ERROR);
	if (ac == 6 && args->must_eat_each <= 0)
		return (ERROR);
	return (SUCCES);
}

int	read_args(t_args **args, char **av, int ac)
{
	if (check_args(av) != 0)
		return (ERROR);
	*args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (free(args), ERROR);
	(*args)->n_philo = ft_atoi(av[1]);
	(*args)->time_to_die = ft_atoi(av[2]);
	(*args)->time_to_eat = ft_atoi(av[3]);
	(*args)->time_to_sleep = ft_atoi(av[4]);
	(*args)->must_eat_each = -1;
	if (ac == 6)
		(*args)->must_eat_each = ft_atoi(av[5]);
	if (protect(*args, ac) != SUCCES)
		return (ERROR);
	else
		return (SUCCES);
}

t_philo	*new_node(t_philo *node, int index, t_args *args)
{
	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->index = index + 1;
	node->args = args;
	node->next = NULL;
	return (node);
}

void	add_back(t_philo **philos, t_philo *philo)
{
	struct t_philo	*back;

	if ((*philos) == NULL)
		*philos = philo;
	if ((*philos)->next == NULL)
	{
		(*philos)->next = philo;
		philo->next = *philos;
	}
	else
	{
		back = (*philos)->next;
		while (back->next != *philos)
			back = back->next;
		back->next = philo;
		philo->next = (*philos);
	}
}
