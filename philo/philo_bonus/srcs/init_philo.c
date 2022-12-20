

#include "../includes/philo.h"

static int	last_meal_sem(t_table **table)
{
	int		i;
	char	*num;
	char	*sem;

	i = -1;
	while (++i < (*table)->info->num)
	{
		num = ft_itoa((*table)->philo[i].id);
		sem = ft_strjoin("last_meal_", num);
		sem_unlink(sem);
		(*table)->philo[i].last_meal = sem_open(sem, O_CREAT, 0644, 1);
		free(sem);
		free(num);
	}
	return (SUCCESS);
}

static int	init_sem(t_table **table)
{
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
	sem_unlink("/death_sem");
	last_meal_sem(table);
	(*table)->info->forks_sem = sem_open("/forks_sem", O_CREAT, 0644,
			(*table)->info->num);
	(*table)->info->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	(*table)->info->death_sem = sem_open("/death_sem", O_CREAT, 0644, 1);
	if ((*table)->info->forks_sem == SEM_FAILED
		|| (*table)->info->print_sem == SEM_FAILED
		|| (*table)->info->death_sem == SEM_FAILED)
	{
		print_msg(SYS_ERR, SEMOPEN_ERR);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	create_process(t_table **table)
{
	int		i;

	i = -1;
	sem_wait((*table)->info->death_sem);
	(*table)->start_time = get_time();
	while (++i < (*table)->info->num)
	{
		(*table)->philo_pid[i] = fork();
		if ((*table)->philo_pid[i] == -1)
		{
			print_msg(SYS_ERR, FORK_ERR);
			close_sem(table);
			free_table(*table);
			return (ERROR);
		}
		else if (!(*table)->philo_pid[i])
		{
			life_cycle(&((*table)->philo[i]));
			close_sem(table);
			free_table(*table);
			exit (SUCCESS);
		}
	}
	return (SUCCESS);
}

int	init_philo(t_table **table)
{
	if (init_sem(table) == ERROR)
		return (ERROR);
	if (create_process(table) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
