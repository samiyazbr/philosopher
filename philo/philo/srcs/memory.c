

#include "../includes/philo.h"

void	free_table(t_table *table)
{
	free(table->forks);
	free(table->threads);
	free(table->mutex);
	free(table->philo);
	free(table->info);
	free(table);
}
