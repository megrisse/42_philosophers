/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:01:02 by megrisse          #+#    #+#             */
/*   Updated: 2022/06/28 16:51:11 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	signe;
	int	rst;

	x = 0;
	signe = 1;
	rst = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			signe *= -1;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		rst = rst * 10 + (str[x++] - 48);
	}
	return (rst * signe);
}

int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		write(2, &str[i], 1);
	return (ERROR);
}

long long	time_in_ms(struct timeval now)
{
	long long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

int	ft_alloc(void *src, size_t size)
{
	*(void **)src = malloc(size);
	if (*(void **)src == NULL)
		return (ERROR);
	memset(*(void **)src, 0, size);
	return (SUCCES);
}

void	print_routine(t_philo *philos, char *str)
{
	long long		ms;
	struct timeval	time;

	pthread_mutex_lock(&philos->infos->mutex);
	gettimeofday(&time, NULL);
	ms = time_in_ms(time) - time_in_ms(philos->infos->creation_time);
	if (!philos->infos->finish)
		printf("%lld\t%d\t%s\n", ms, philos->num + 1, str);
	pthread_mutex_unlock(&philos->infos->mutex);
}