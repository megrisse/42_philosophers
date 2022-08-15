/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:09:36 by megrisse          #+#    #+#             */
/*   Updated: 2022/08/15 03:05:02 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

#define SUCCES 0
#define ERROR  1

typedef struct t_args
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_each;
	long long		creation_time;
	pthread_mutex_t	print;
}	t_args;


typedef struct t_philo
{
	t_args			*args;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				n_eating;
	int				index;
	long long		last_meal;
	int				finish;
	struct t_philo	*next;
}	t_philo;

void		add_back(t_philo **philos, t_philo *philo);
t_philo		*new_node(t_philo *node, int index, t_args *args);
void		ft_usleep(long long time);
long long	get_time(void);
long		ft_atoi(char *str);
int			check_args(char **av);
int			read_args(t_args **args, char **av, int ac);
int			inits_philos(t_philo**philos, char **av, int ac);
int 		philos_list(t_philo **philos, int n, t_args *args);
void		free_philos(t_philo *philos, int x);
void		take_forks(t_philo *philo, int x);
void    	print_routine(t_philo *philo, char *str, int key);
int 		init_sim(t_philo **philos);
void    	*routine(void *ptr);
int 		dead_of_philo(t_philo **philo);
void		destroy_mutexes(t_philo *philo);


#endif