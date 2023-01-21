/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:51:19 by szubair           #+#    #+#             */
/*   Updated: 2023/01/21 15:05:10 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int check_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		print_msg(PAR_ERR, NDGT_ERR);
		return (ERROR);
	}
	i++;
	if (i > 11 || ft_atoi(str) > INT_MAX)
	{
		print_msg(PAR_ERR, NMAX_ERR);
		return (ERROR);
	}
	return (SUCCESS);
}

int parser(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 6 || ac < 5)
	{
		print_msg(PAR_ERR, INV_ARG);
		return (ERROR);
	}
	while (av[++i])
	{
		if (check_number(av[i]) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}