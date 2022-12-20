
#include "../includes/philo.h"

static int	check_fork(t_philo *philo, pthread_mutex_t *lock, int f)
{
	int		*fork;
	int		forkn;
	int		ret;

	pthread_mutex_lock(lock);
	if (!f)
	{
		fork = philo->left_fork;
		forkn = philo->left_forkn;
	}
	else
	{
		fork = philo->right_fork;
		forkn = philo->right_forkn;
	}
	if ((*fork != philo->id && *fork != 0 && *fork != -1)
		|| (*fork == -1 && philo->id % 2 != 0))
	{
		*fork = USED;
		ret = print_state(philo, forkn);
	}
	else
		ret = ERROR;
	pthread_mutex_unlock(lock);
	return (ret);
}

static void	which_fork(t_philo *philo, int *side, pthread_mutex_t **lock, int f)
{
	if (f == 0)
	{
		if (philo->id % 2 == 0)
		{
			*side = LEFT;
			*lock = philo->left_mutex;
		}
		else
		{
			*side = RIGHT;
			*lock = philo->right_mutex;
		}
		return ;
	}
	if (philo->id % 2 == 0)
	{
		*side = RIGHT;
		*lock = philo->right_mutex;
	}
	else
	{
		*side = LEFT;
		*lock = philo->left_mutex;
	}
}

int	forks(t_philo *philo)
{
	int				ret;
	int				side;
	int				fork_check;
	pthread_mutex_t	*lock;

	fork_check = 0;
	which_fork(philo, &side, &lock, fork_check);
	while (fork_check < 2)
	{
		if (philo->neat == 0 && fork_check == 0)
			philo->last_eat = get_time();
		ret = check_fork(philo, lock, side);
		if (ret == SUCCESS)
		{
			fork_check++;
			which_fork(philo, &side, &lock, fork_check);
		}
		else if (ret == DEAD)
			return (DEAD);
		if (print_state(philo, DEAD) == DEAD)
			return (DEAD);
	}
	philo->state = EAT;
	return (SUCCESS);
}
