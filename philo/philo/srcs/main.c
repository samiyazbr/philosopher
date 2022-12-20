
#include "../includes/philo.h"

t_table	*init_struct(char **av)
{
	t_table	*table;

	table = init_table_struct(av);
	if (!table)
		return (NULL);
	table->info = init_info_strcut(av);
	if (!table->info)
	{
		free(table->forks);
		free(table);
		return (NULL);
	}
	table->philo = init_philo_struct(table);
	if (!table->philo)
	{
		free(table->info);
		free(table->forks);
		free(table);
		return (NULL);
	}
	return (table);
}

int	philo(int ac, char **av)
{
	t_table		*table;

	if (parser(ac, av) == ERROR)
		return (ERROR);
	table = init_struct(av);
	if (!table)
		return (ERROR);
	if (init_threads(&table) == ERROR)
		return (ERROR);
	collect_philo(&table);
	free_table(table);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (philo(ac, av) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
