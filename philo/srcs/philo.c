/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:06:55 by szubair           #+#    #+#             */
/*   Updated: 2023/01/26 21:11:03 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_table **table)
{
	int		i;

	i = -1;
	if (pthread_mutex_init(&(*table)->print, NULL))
	{
		print_msg(SYS_ERR, MUTEX_ERR);
		free_table(*table);
		return (ERROR);
	}
	while (++i < (*table)->info->num)
	{
		if (pthread_mutex_init(&(*table)->mutex[i], NULL))
		{
			print_msg(SYS_ERR, MUTEX_ERR);
			free_table(*table);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	create_threads(t_table **table)
{
	int		i;

	i = -1;
	(*table)->start_time = get_time();
	while (++i < (*table)->info->num)
	{
		if (pthread_create(&(*table)->threads[i],
				NULL, &life_cycle, &(*table)->philo[i]))
		{
			print_msg(SYS_ERR, THREAD_ERR);
			free_table(*table);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	init_threads(t_table **table)
{
	if (init_mutex(table) == ERROR)
		return (ERROR);
	if (create_threads(table) == ERROR)
		return (ERROR);
	return (SUCCESS);
}