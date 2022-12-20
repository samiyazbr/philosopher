
#include "../includes/philo.h"

static void	terminate_proc(pid_t *pid, int num, size_t t_eat)
{
	int		i;

	i = -1;
	mysleep(t_eat);
	while (++i < num)
	{
		if (kill(pid[i], SIGKILL))
			print_msg(SYS_ERR, KILL_ERR);
	}
}

void	free_table(t_table *table)
{
	free(table->philo);
	free(table->info);
	free(table->philo_pid);
	free(table);
}

static void	wait_philo(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->info->num)
		waitpid((*table)->philo_pid[i], NULL, 0);
}

void	close_sem(t_table **table)
{
	sem_close((*table)->info->forks_sem);
	sem_close((*table)->info->print_sem);
	sem_close((*table)->info->death_sem);
}

void	collect_philo(t_table **table)
{
	sem_wait((*table)->info->death_sem);
	terminate_proc((*table)->philo_pid,
		(*table)->info->num, (*table)->info->t_eat);
	wait_philo(table);
	close_sem(table);
}
