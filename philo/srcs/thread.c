/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threaad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:44:15 by szubair           #+#    #+#             */
/*   Updated: 2023/01/28 18:44:40 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	join_threads(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->info->num)
	{
		if (pthread_join((*table)->threads[i], NULL))
			print_msg(SYS_ERR, JOIN_ERR);
	}
}

static void	destroy_mutex(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->info->num)
	{
		if (pthread_mutex_destroy(&(*table)->mutex[i]))
			print_msg(SYS_ERR, DMUTEX_ERR);
	}
	if (pthread_mutex_destroy(&(*table)->print))
		print_msg(SYS_ERR, DMUTEX_ERR);
}

void	collect_philo(t_table **table)
{
	join_threads(table);
	destroy_mutex(table);
}