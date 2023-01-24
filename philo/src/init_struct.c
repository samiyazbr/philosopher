#include "../include/philo.h"

int	init_forks(t_table **table, int num)
{
	int		i;

	i = -1;
	(*table)->forks = (int *)malloc(sizeof(int) * num);
	if (!(*table)->forks)
	{
		free(*table);
		print_msg(SYS_ERR, MALLOC_ERR);
		return (ERROR);
	}
	while (++i < num)
		(*table)->forks[i] = -1;
	return (SUCCESS);
}

t_table	*init_struct_table(char **av)
{
	t_table		*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	table->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* ft_atoi(av[1]));
	table->threads = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	if (!table->mutex || !table->threads)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		if (table->mutex)
			free(table->mutex);
		if (table->threads)
			free(table->threads);
		free(table);
		return (NULL);  
	}
	table->check_death = 0;
	if (init_forks(&table, ft_atoi(av[1])) == ERROR)
		return (NULL);
	return (table);
}

t_info	*init_struct_info(char **av)
{
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	info->num = ft_atoi(av[1]);
	info->t_death = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	if (av[5])
		info->repeat = ft_atoi(av[5]);
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

void	fill_philo(t_table *table, t_philo *philo, int id)
{
	philo->id = id;
	philo->state = P_FORK;
	philo->check_death = &table->check_death;
	philo->start_time = &table->start_time;
	philo->left_fork_num = id;
	philo->left_fork = &table->forks[id - 1];
	philo->left_mutex = &table->mutex[id - 1];
	if (id == table->info->num)
	{
		philo->right_fork_num = 1;
		philo->right_fork = &table->forks[0];
		philo->right_mutex = &table->mutex[0];
	}
	else
	{
		philo->right_fork_num = id + 1;
		philo->right_fork = &table->forks[id];
		philo->right_mutex = &table->mutex[id];
	}
	philo->info = table->info;
	philo->num_eat = 0;
	philo->last_eat = 0;
	philo->print = &table->print;
}

t_philo	*init_struct_philo(t_table *table)
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
		fill_philo(table, &(philo[i]), i + 1);
	return (philo);
}
