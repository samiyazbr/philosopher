/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:23:22 by szubair           #+#    #+#             */
/*   Updated: 2023/01/28 18:08:37 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	fork_log(int n, int fork_n, int current)
{
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo ", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(" has picked fork ", 1);
	ft_putnbr_fd(fork_n, 1);
	ft_putstr_fd(" 🥢\n", 1);
}

static void	eating_log(int n, int current)
{
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo ", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(" is eating 🍝\n", 1);
}

static void	sleeping_log(int n, int current)
{
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo ", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(" is sleeping 😴\n", 1);
}

static void	thinking_log(int n, int current)
{
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo ", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(" is thinking 💭\n", 1);
}

void	pick_log(t_philo *philo, size_t current, int fork_n)
{
	if (philo->state == P_FORK)
		fork_log(philo->id, fork_n, current);
	else if (philo->state == EAT)
		eating_log(philo->id, current);
	else if (philo->state == SLEEP)
		sleeping_log(philo->id, current);
	else if (philo->state == THINK)
		thinking_log(philo->id, current);
}


