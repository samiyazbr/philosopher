
#include "../includes/philo.h"

static t_table	*init_table_struct(char **av)
{
	t_table		*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	table->philo_pid = (pid_t *)malloc(sizeof(pid_t) * ft_atox(av[1]));
	if (!table->philo_pid)
	{
		free (table);
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	return (table);
}

static t_info	*init_info_strcut(char **av)
{
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	info->num = ft_atox(av[1]);
	info->t_death = ft_atox(av[2]);
	info->t_eat = ft_atox(av[3]);
	info->t_sleep = ft_atox(av[4]);
	if (av[5])
		info->repeat = ft_atox(av[5]);
	else
		info->repeat = -1;
	if (info->num == 0 || info->t_death == 0
		|| info->t_eat == 0 || info->t_sleep == 0)
	{
		print_msg(PAR_ERR, ZERO_ERR);
		free(info);
		return (NULL);
	}
	return (info);
}

static void	fill_philo_struct(t_table *table, t_philo *philo, int id)
{
	(*philo).id = id;
	(*philo).state = P_FORK;
	(*philo).start_time = &table->start_time;
	(*philo).info = table->info;
	(*philo).neat = 0;
	(*philo).last_eat = 0;
}

static t_philo	*init_philo_struct(t_table *table)
{
	int			i;
	t_philo		*philo;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * (table->info->num));
	if (!philo)
	{
		free(table);
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	while (++i < table->info->num)
		fill_philo_struct(table, &(philo[i]), i + 1);
	return (philo);
}

t_table	*init_struct(char **av)
{
	t_table	*table;

	table = init_table_struct(av);
	if (!table)
		return (NULL);
	table->info = init_info_strcut(av);
	if (!table->info)
	{
		free(table);
		return (NULL);
	}
	table->philo = init_philo_struct(table);
	if (!table->philo)
	{
		free(table->info);
		free(table);
		return (NULL);
	}
	return (table);
}
