#include	"../include/philo.h"

t_table *init_struct(char **av)
{
	t_table *table;

	table = init_struct_table(av);
	if (!table)
		return (NULL);
	table->info = init_struct_info(av);
	if (!table->info)
	{
		free(table->fork);
		free(table);
		return (NULL);
	}
	table->philo = init_struct_philo(av);
	if (!table->philo)
	{
		free(table->info);
		free(table->fork);
		free(table);
		return (NULL);
	}
	return (table);
}

int philo(int ac,char **av)
{
	t_table *table;
	if (parser(ac,av) == 1)
		return (1);
	table = init_struct(av);
	if (!table)
		return (1);
	if (init_thread(&table) == 1)
		return (1);
	collect_philo(&table);
	free_table(table);
	return (0);
}

int	main(int ac, char **av)
{
	if (philo(ac,av) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}