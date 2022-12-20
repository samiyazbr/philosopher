

#include "../includes/philo.h"

size_t	get_time(void)
{
	size_t			ret;
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
	{
		ft_putstr_fd("philo: getting the time failed\n", 2);
		return (-1);
	}
	ret = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (ret);
}

size_t	time_stamp(time_t start)
{
	return (get_time() - start);
}

int	mysleep(t_philo *philo, size_t duration)
{
	size_t	time;

	time = get_time();
	while (get_time () < time + duration)
	{
		if (check_death(philo->last_eat, philo->info->t_death) == DEAD)
		{
			pthread_mutex_lock(philo->print);
			if (*philo->check_death != DEAD)
				dead_log(philo->id, time_stamp(*philo->start_time));
			*philo->check_death = DEAD;
			pthread_mutex_unlock(philo->print);
			return (DEAD);
		}
		usleep(500);
	}
	return (SUCCESS);
}
