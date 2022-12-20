
#include "../includes/philo.h"

int	forks(t_philo *philo)
{
	sem_wait(philo->info->forks_sem);
	if (philo->neat == 0)
	{
		sem_wait(philo->last_meal);
		philo->last_eat = get_time();
		sem_post(philo->last_meal);
	}
	print_state(philo);
	sem_wait(philo->info->forks_sem);
	print_state(philo);
	philo->state = EAT;
	return (SUCCESS);
}

int	eat(t_philo *philo)
{
	print_state(philo);
	sem_wait(philo->last_meal);
	philo->last_eat = get_time();
	sem_post(philo->last_meal);
	mysleep(philo->info->t_eat);
	sem_post(philo->info->forks_sem);
	sem_post(philo->info->forks_sem);
	philo->neat++;
	philo->state = SLEEP;
	return (SUCCESS);
}

int	sleeep(t_philo *philo)
{
	print_state(philo);
	mysleep(philo->info->t_sleep);
	philo->state = THINK;
	return (SUCCESS);
}

int	think(t_philo *philo)
{
	print_state(philo);
	philo->state = P_FORK;
	return (SUCCESS);
}
