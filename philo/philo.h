/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:53:11 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 14:26:26 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "sys/time.h"
# include "pthread.h"
# include "stdlib.h"
# include "string.h"

# define SUCCES 0
# define ERROR 1

typedef struct s_infos
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				must_eat_each;
	int				time_to_sleep;
	int				finish;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	t_philo			*philos;
	int				die;
	struct timeval	creation_time;
}				t_infos;

typedef struct s_philo
{
	int				num;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	check_mutex;
	t_infos			*infos;
}				t_philo;

/********   utils  ********/
long long	time_in_ms(struct timeval now);
int			ft_atoi(const char *str);
int			print_error(char *str);
int			ft_alloc(char *src, size_t size);

/*********  parsing    ********/
void		get_args(t_infos info, int ac, char **av);
int			check_args(t_infos infos, int ac);
int			initialize(t_infos *infos, int ac, char **av);

#endif