/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:07:16 by szubair           #+#    #+#             */
/*   Updated: 2023/01/21 18:26:06 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	sys_error(int num)
{
	if (num == MALLOC_ERR)
		ft_putendl_fd("Error: malloc fail", 2);
	else if (num == MUTEX_ERR)
		ft_putendl_fd("Error: mutex lock fail", 2);
	else if (num == THREAD_ERR)
		ft_putendl_fd("Error: creating threads fail", 2);
	else if (num == JOIN_ERR)
		ft_putendl_fd("Error: joining threads fail", 2);
	else if (num == DMUTEX_ERR)
		ft_putendl_fd("Error: destroying mutex fail", 2);
}

static void	parser_err(int num)
{
	if (num == INV_ARG)
		ft_putendl_fd("Error: invalid number of arguments", 2);
	else if (num == NDGT_ERR)
		ft_putendl_fd("Error: non-digit character", 2);
	else if (num == NMAX_ERR)
		ft_putendl_fd("Error: number is more than int max", 2);
	else if (num == ZERO_ERR)
		ft_putendl_fd("Error: argument is equal to zero", 2);
}

void	print_msg(int type, int num)
{
	ft_putstr_fd(BOLDRED, 2);
	if (type == SYS_ERR)
		sys_error(num);
	else if (type == PAR_ERR)
		parser_err(num);
	ft_putstr_fd(RESET, 2);
}