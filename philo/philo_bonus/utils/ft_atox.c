
#include "../includes/philo.h"

size_t	ft_atox(const char *str)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + (str[i++] - 48);
	return (num);
}

static int	num_len(long num, long *divide)
{
	int	count;

	count = 1;
	while (num / *divide > 0)
	{
		*divide *= 10;
		count++;
	}
	return (count);
}

/*
* changes int n into *str
* return the new str
*/
char	*ft_itoa(int n)
{
	int			i;
	int			neg;
	long		divide;
	long		num;
	char		*str;

	i = 0;
	neg = 0;
	num = (long)n;
	divide = 10;
	if (num < 0)
		num *= (++neg * -1);
	str = (char *)malloc(sizeof(char) * (num_len(num, &divide) + neg + 1));
	if (neg == 1)
		str[i++] = '-';
	divide = 10;
	neg += num_len(num, &divide);
	while (i < neg)
	{
		divide /= 10;
		str[i++] = (num / divide) + 48;
		num %= divide;
	}
	str[i] = 0;
	return (str);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	while (s2[++j])
	{
		str[i++] = s2[j];
	}
	str[i] = 0;
	return (str);
}
