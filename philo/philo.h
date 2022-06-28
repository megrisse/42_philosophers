/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:53:11 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 17:29:47 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

# define SUCCES 0
# define ERROR 1

typedef struct s_philo
{
	int				num;
	int				num_of_eat;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	check_mutex;
	struct s_infos	*infos;
	struct timeval	last_meal;
}				t_philo;

typedef struct s_infos
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				must_eat_each;
	int				time_to_sleep;
	int				sated;
	int				finish;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	t_philo			*philos;
	int				die;
	struct timeval	creation_time;
}				t_infos;

/********   utils  ********/
long long	time_in_ms(struct timeval now);
int			ft_atoi(const char *str);
int			print_error(char *str);
int			ft_alloc(void *src, size_t size);
void		print_routine(t_philo *philos, char *str);

/*********  parsing    ********/
int			initialize(t_infos *infos, int ac, char **av);

/***** routine ****/
void		*routine(void *av);
void		*check_philo_die(void *av);
void		*check_philos_eat(void *av);

#endif