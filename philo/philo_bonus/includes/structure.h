

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_info
{
	int			num;
	int			t_eat;
	int			t_death;
	int			t_sleep;
	int			repeat;
	sem_t		*meals_sem;
	sem_t		*forks_sem;
	sem_t		*print_sem;
	sem_t		*death_sem;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				state;
	size_t			*start_time;
	int				neat;
	size_t			last_eat;
	sem_t			*last_meal;
	t_info			*info;
}	t_philo;

typedef struct s_table
{
	pid_t	*philo_pid;
	size_t	start_time;
	t_info	*info;
	t_philo	*philo;
}	t_table;

#endif