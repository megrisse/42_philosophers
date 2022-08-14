#include "philo.h" 

int	inits_philos(t_philo**philos, char **av, int ac)
{
	t_args	*args;

	args = NULL;
	if (read_args(&args, av, ac) != SUCCES)
		return (printf("error arguments\n"), ERROR);
	if (philos_list(philos, args->n_philo, args) != SUCCES)
		return (printf("error value of number of philosophers\n") \
			,free_philos(*philos, 0), ERROR);
	return (SUCCES);
}

int philos_list(t_philo **philos, int n, t_args *args)
{
    int     i;
    t_philo *node;

    i = 0;
    while (i < n)
    {
        node = new_node(node, i, args);
        if (!node)
            return (ERROR);
        add_back(philos, node);
        i++;
    }
    return (SUCCES);
}

int init_sim(t_philo **philos)
{
    int i;
    t_philo *ptr = *philos;
    i = 0;
    if (pthread_mutex_init(&ptr->args->print, NULL) != SUCCES)  
        return (ERROR);
    while (i++ < (*philos)->args->n_philo)
    {
        if (pthread_mutex_init(&ptr->fork, NULL) != SUCCES)  
            return (ERROR);
        ptr = ptr->next;
    }
    i = 0;
    ptr = *philos;
    while (i++ < (*philos)->args->n_philo)
    {
        if (pthread_create(&ptr->thread, NULL, &routine, (void *)ptr) != SUCCES)  
            return (ERROR);
        if (pthread_detach(ptr->thread) != SUCCES)
            return (ERROR);
        ptr = ptr->next;
    }
    return (SUCCES);
}

void    take_forks(t_philo *philo, int x)
{
    if (x == 0)
    {
        pthread_mutex_lock(&philo->fork);
        print_routine(philo, "taking a fork");
        pthread_mutex_lock(&philo->next->fork);
        print_routine(philo, "taking a fork");
    }
    else if (x == 1)
    {
        pthread_mutex_unlock(&philo->fork);
        pthread_mutex_unlock(&philo->next->fork);
    }
}


void    *routine(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;
    philo->n_eating = 0;
    philo->finish = 0;
    if (philo->index % 2 == 0)
        ft_usleep((philo->args->time_to_die / 2) * 1000);
    philo->last_meal = get_time();
    while (philo->args->must_eat_each != philo->n_eating)
    {
        take_forks(philo, 0);
        print_routine(philo, "is eating");
        ft_usleep(philo->args->time_to_eat * 1000);
        philo->last_meal = get_time();
        take_forks(philo, 1);
        print_routine(philo, "is sleeping");
        ft_usleep(philo->args->time_to_sleep * 1000);
        print_routine(philo, "is thinking");
        philo->n_eating++;
    }
    philo->finish = 1;
    return (NULL);
}