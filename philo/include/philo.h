/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:57:22 by szubair           #+#    #+#             */
/*   Updated: 2023/01/24 20:32:29 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

/**************************************************************/

# define SUCCESS 0
# define ERROR	 1

//FORKS
# define LEFT	0		// left fork
# define RIGHT	1		// right fork
# define FREE	1			// fork is available to pick
# define USED	0			// fork is being used by a philo

//PHILOSOPHER STATE
# define DEAD	-2		// dead
# define THINK	0		// thinking
# define P_FORK	1		// picking fork
# define EAT	2		// eating
# define SLEEP	3		// sleeping

//ERROR TYPE
# define SYS_ERR 0		// system error
# define PAR_ERR 1		// parser error

//SYSTEM ERROR
# define MALLOC_ERR	0	// malloc fails
# define MUTEX_ERR	1	// creating mutex lock fails
# define THREAD_ERR 2	// creating thread fails
# define JOIN_ERR	3	// joining thread fails
# define DMUTEX_ERR	4	// destroying mutex fails

//PARSER ERROR
# define INV_ARG	0	// invalid argument
# define NDGT_ERR	1	// non-digit charachter
# define NMAX_ERR	2	// number more than int max
# define ZERO_ERR	3	// one of the arguments is equal to zero

/**************************************************************/
typedef struct s_info
{
	int	num;
	int	t_eat;
	int	t_death;
	int	t_sleep;
	int	repeat;
}	t_info;

//num: number of philosophers
//t_eat: time to eat
//t_death: time to die
//t_sleep: time to sleep
//repeat: number of times each philosopher should eat

/***************************************************************/
typedef struct s_philo
{
	int				id;
	int				state;
	int				*check_death;
	size_t			*start_time;
	int				left_fork_num;
	int				right_fork_num;
	int				*left_fork;
	int				*right_fork;
	int				num_eat;
	size_t			last_eat;
	t_info			*info;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	*print;
}	t_philo;

//id: philosopher id
//state: philosopher status
//			-1: dead
//			 0: didn't start yet / thinking
//			 1: picked forks
//			 2: eating
//			 3: sleeping
//start_time: system time when the first thread was created
//check_death: checks if any philosopher died
//left_fork_num: left fork number
//right_fork_num: right fork number
//left_fork: fork on the left                       
//right_fork: fork on the right
//num_eat: how many times the philosopher ate
//repeat: number of times each philosopher should eat
//last_eat: last time philosopher ate
//left_mutex: mutex for the left fork
//right_mutex: mutex for the right fork
//print: mutex that is shared between all philosophers to print

/***************************************************************/
typedef struct s_table
{
	int				check_death;
	size_t			start_time;
	int				*fork;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	t_info			*info;
	t_philo			*philo;
}	t_table;

//check_death: check if any philo died
//				0: no philosopher died
//				1: a philosopher died
//start_time: system time when the first thread was created
//eat: time to eat
//death: time to die
//sleep: time to sleep
//repeat: number of times each philosopher should eat
//fork: each fork status
//threads: philosophers threads
//mutex: mutex locks array
//print: printing lock
//philo: philosophers structure

/***************************************************************/

int		parser(int ac, char **av);
t_table	*init_struct(char **av);
int		philo(int ac,char **av);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
static	int check_number(char *str);
void	print_msg(int type, int num);
int	init_forks(t_table **table, int num);
t_table	*init_struct_table(char **av);
t_info	*init_struct_info(char **av);
void	fill_philo(t_table *table, t_philo *philo, int id);
t_philo	*init_struct_philo(t_table *table);
int	ft_atoi(t_data *data, char *str, char **args);

#endif