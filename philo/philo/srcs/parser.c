
#include "../includes/philo.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			print_msg(PAR_ERR, NDGT_ERR);
			return (ERROR);
		}
		i++;
		if (i > 11 || ft_atox(str) > INT_MAX)
		{
			print_msg(PAR_ERR, NMAX_ERR);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	parser(int ac, char **av)
{
	int		i;

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
