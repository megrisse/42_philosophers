#include "philo.h"


int main(int ac, char **av)
{
    t_philo *philos;

    philos = NULL;
    if (ac < 5 || ac > 6)
        return(printf("ARGUMENTS ERROR\n"), ERROR);
    if (inits_philos(&philos, av, ac) != SUCCES)
        return (ERROR);
    if (init_sim(&philos) != SUCCES)
        return (ERROR);
    if (dead_of_philo(&philos) != SUCCES)
        return (ERROR);
}