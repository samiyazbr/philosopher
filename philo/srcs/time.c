/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:44:23 by szubair           #+#    #+#             */
/*   Updated: 2023/01/28 18:44:25 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	get_time(void)
{
	size_t			millisec;
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
	{
		ft_putstr_fd("philo: getting the time failed\n", 2);
		return (-1);
	}
	millisec = (current.tv_sec * 1000) + (current.tv_usec / 1000); // convertion into millisecond
	return (millisec);
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
