

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	int		ret;

	ret = SUCCESS;
	if (print_state(philo, -1) == DEAD)
		ret = DEAD;
	philo->last_eat = get_time();
	if (mysleep(philo, philo->info->t_eat) == DEAD)
		ret = DEAD;
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = philo->id;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = philo->id;
	pthread_mutex_unlock(philo->right_mutex);
	philo->neat++;
	philo->state = SLEEP;
	return (ret);
}

int	sleeep(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	if (ret == DEAD)
		return (DEAD);
	if (mysleep(philo, philo->info->t_sleep) == DEAD)
		return (DEAD);
	ret = print_state(philo, DEAD);
	philo->state = THINK;
	return (ret);
}

int	think(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	philo->state = P_FORK;
	return (ret);
}
