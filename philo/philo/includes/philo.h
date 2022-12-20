
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include "structure.h"

/********************* DEFINES *********************/
# define SUCCESS 0
# define ERROR	 1

// FORKS
# define LEFT	0		// left fork
# define RIGHT	1		// right fork
# define FREE	1			// fork is available to pick
# define USED	0			// fork is being used by a philo

//	PHILOSOPHER STATE
# define DEAD	-2		// dead
# define THINK	0		// thinking
# define P_FORK	1		// picking fork
# define EAT	2		// eating
# define SLEEP	3		// sleeping

//	ERROR TYPE
# define SYS_ERR 0		// system error
# define PAR_ERR 1		// parser error

//	SYSTEM ERROR
# define MALLOC_ERR	0	// malloc fails
# define MUTEX_ERR	1	// creating mutex lock fails
# define THREAD_ERR 2	// creating thread fails
# define JOIN_ERR	3	// joining thread fails
# define DMUTEX_ERR	4	// destroying mutex fails

//	PARSER ERROR
# define INV_ARG	0	// invalid argument
# define NDGT_ERR	1	// non-digit charachter
# define NMAX_ERR	2	// number more than int max
# define ZERO_ERR	3	// one of the arguments is equal to zero

/*********************  COLORS  *********************/
# define RESET			"\033[0m"			// Reset
# define BLACK			"\033[30m"			// Black
# define RED			"\033[31m"			// Red
# define GREEN			"\033[32m"			// Green
# define YELLOW			"\033[33m"			// Yellow
# define BLUE			"\033[34m"			// Blue
# define MAGENTA		"\033[35m"			// Magenta
# define CYAN			"\033[36m"			// Cyan
# define WHITE			"\033[37m"			// White
# define BOLDBLACK		"\033[1m\033[30m"	// Bold Black
# define BOLDRED		"\033[1m\033[31m"	// Bold Red
# define BOLDGREEN		"\033[1m\033[32m"	// Bold Green
# define BOLDYELLOW		"\033[1m\033[33m"	// Bold Yellow
# define BOLDBLUE		"\033[1m\033[34m"	// Bold Blue
# define BOLDMAGENTA	"\033[1m\033[35m"	// Bold Magenta
# define BOLDCYAN		"\033[1m\033[36m"	// Bold Cyan
# define BOLDWHITE		"\033[1m\033[37m"	// Bold White

/*********************  PHILO *********************/
int		parser(int ac, char **av);

t_table	*init_struct(char **av);

void	print_msg(int type, int num);
int		print_state(t_philo *philo, int fork_n);

void	free_table(t_table *table);

int		init_threads(t_table **table);
void	collect_philo(t_table **table);
t_table	*init_table_struct(char **av);
t_info	*init_info_strcut(char **av);
void	fill_philo_struct(t_table *table, t_philo *philo, int id);
t_philo	*init_philo_struct(t_table *table);

void	*life_cycle(void *p);
int		forks(t_philo *philo);
int		eat(t_philo *philo);
int		sleeep(t_philo *philo);
int		think(t_philo *philo);

int		check_death(size_t last_eat, size_t death_time);
void	dead_log(int n, int current);

void	pick_log(t_philo *philo, size_t current, int fork_n);

size_t	get_time(void);
size_t	time_stamp(time_t start);
int		mysleep(t_philo *philo, size_t duration);

/*********************  UTILS  *********************/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
size_t	ft_atox(const char *str);

#endif
