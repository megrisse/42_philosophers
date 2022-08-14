#include "philo.h"

void    print_routine(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->args->print);
	printf("%lld\t%d\t%s\n", (get_time() - philo->args->creation_time) / 1000
    , philo->index, str);
    pthread_mutex_unlock(&philo->args->print);
}

int dead_of_philo(t_philo **philo)
{
    t_philo *ptr;
    int     i;

    i = 0;
    ptr = *philo;
    while(1)
    {
        if (ptr->finish == 0 && get_time() - ptr->last_meal > ptr->args->time_to_die * 1000)
            return (print_routine(ptr, "is dead"), ERROR);
        if (ptr->finish == 1)
        {
            i++;
            ptr->finish++;
        }
        if (i == ptr->args->must_eat_each)
            break ;
    }
    return (SUCCES);
}