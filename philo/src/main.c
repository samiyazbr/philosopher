/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:57:40 by szubair           #+#    #+#             */
/*   Updated: 2023/01/21 14:23:33 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/philo.h"

t_table *init_struct(char **av)
{
	t_table *table;

	table = init_struct_table(av);
	if (!table)
		return (NULL);
	table->info = init_struct_info(av);
	if (!table->info)
	{
		free(table->fork);
		free(table);
		return (NULL);
	}
	table->philo = init_struct_philo(av);
	if (!table->philo)
	{
		free(table->info);
		free(table->fork);
		free(table);
		return (NULL);
	}
	return (table);
}

int philo(int ac,char **av)
{
	t_table *table;
	if (parser(ac,av) == ERROR)
		return (ERROR);
	table = init_struct(av);
	if (!table)
		return (ERROR);
	if (init_thread(&table) == ERROR)
		return (ERROR);
	collect_philo(&table);
	free_table(table);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (philo(ac,av) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}