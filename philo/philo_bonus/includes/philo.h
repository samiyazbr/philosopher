

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include "structure.h"

/********************* DEFINES *********************/
# define SUCCESS		0
# define ERROR			1

// FORKS
# define LEFT			0		// left fork
# define RIGHT			1		// right fork
# define FREE			1			// fork is available to pick
# define USED			0			// fork is being used by a philo

//	PHILOSOPHER STATE
# define DEAD			-2		// dead
# define THINK			0		// thinking
# define P_FORK			1		// picking fork
# define EAT			2		// eating
# define SLEEP			3		// sleeping

//	ERROR TYPE
# define SYS_ERR 		0		// system error
# define PAR_ERR 		1		// parser error

//	SYSTEM ERROR
# define MALLOC_ERR		0	// malloc failed
# define THREAD_ERR 	2	// creating thread failed
# define JOIN_ERR		3	// joining thread failed
# define SEMOPEN_ERR 	4	// semopen function failed
# define FORK_ERR		5	// fork function failed
# define KILL_ERR		6	// kill function failed

//	PARSER ERROR
# define INV_ARG		0	// invalid argument
# define NDGT_ERR		1	// non-digit charachter
# define NMAX_ERR		2	// number more than int max
# define ZERO_ERR		3	// one of the arguments is equal to zero

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
int		print_state(t_philo *philo);

void	free_table(t_table *table);

int		init_philo(t_table **table);
void	close_sem(t_table **table);
void	collect_philo(t_table **table);

void	life_cycle(t_philo *philo);
int		forks(t_philo *philo);
int		eat(t_philo *philo);
int		sleeep(t_philo *philo);
int		think(t_philo *philo);

size_t	get_time(void);
size_t	time_stamp(size_t start);
void	mysleep(size_t duration);

/*********************  UTILS  *********************/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
size_t	ft_atox(const char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif