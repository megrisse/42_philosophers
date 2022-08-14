#include "philo.h"

long	ft_atoi(char *str)
{
	long	resultat;
	long	signe;
	int		i;

	resultat = 0;
	signe = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(50);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	free_philos(t_philo *philos, int x)
{
	t_philo	*ptr;
	int		i;

	ptr = philos;
	i = x;
	i = 0;
	//if (x == 1)
	//	destroy_mutex(philos);
	if (!philos)
		return ;
	while (1)
	{
		if (i == ptr->args->n_philo - 1)
		{
			free(ptr->args);
			free(ptr);
			return ;
		}
		philos = philos->next;
		free(ptr);
		ptr = philos;
		i++;
	}
}