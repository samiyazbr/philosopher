

#include "../includes/philo.h"

/*
 * checks if int C is digit (1 to 9)
 */
int	ft_isdigit(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}
