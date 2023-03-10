/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:39:18 by szubair           #+#    #+#             */
/*   Updated: 2023/01/26 19:31:41 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}
