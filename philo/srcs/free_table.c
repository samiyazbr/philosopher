/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:43:40 by szubair           #+#    #+#             */
/*   Updated: 2023/01/28 18:43:42 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_table(t_table *table)
{
	free(table->forks);
	free(table->threads);
	free(table->mutex);
	free(table->philo);
	free(table->info);
	free(table);
}