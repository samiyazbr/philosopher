/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:32:13 by szubair           #+#    #+#             */
/*   Updated: 2023/01/24 20:32:20 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sign(char c, int *sign, int *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
		{
			*sign = -1;
			*i += 1;
		}
	}
}

int	ft_atoi(t_data *data, char *str, char **args)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	ft_sign(str[i], &sign, &i);
	if (!ft_isdigit(str[i]))
		free_args(data, args);
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + str[i] - '0';
		i++;
		if (((res > 2147483647) && (sign == 1)) \
		|| ((res > 2147483648) && (sign == -1)))
			free_args(data, args);
	}
	if ((!ft_isdigit(str[i]) && str[i]) || i > 12)
		free_args(data, args);
	return (res * sign);
}
