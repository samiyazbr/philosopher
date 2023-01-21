/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:24:44 by szubair           #+#    #+#             */
/*   Updated: 2023/01/21 18:32:51 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int d, int fd)
{
	if (d == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (d < 0)
	{
		ft_putchar_fd('-', fd);
		d = -d;
	}
	if (d >= 0 && d <= 9)
		ft_putchar_fd(d + '0', fd);
	if (d > 9)
	{
		ft_putnbr_fd(d / 10, fd);
		ft_putnbr_fd(d % 10, fd);
	}
}
