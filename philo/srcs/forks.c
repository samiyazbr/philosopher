/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:43:33 by szubair           #+#    #+#             */
/*   Updated: 2023/01/28 18:43:35 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_fork(t_philo *philo, pthread_mutex_t *lock, int f)
{
	int		*fork;
	int		fork_num;
	int		ret;

	pthread_mutex_lock(lock);
	if (!f)
	{
		fork = philo->left_fork;
		fork_num = philo->left_fork_num;
	}
	else
	{
		fork = philo->right_fork;
		fork_num = philo->right_fork_num;
	}
	if ((*fork != philo->id && *fork != 0 && *fork != -1)
		|| (*fork == -1 && philo->id % 2 != 0))
	{
		*fork = USED;
		ret = print_state(philo, fork_num);
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
		if (philo->num_eat == 0 && fork_check == 0)
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
