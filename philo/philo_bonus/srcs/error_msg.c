

#include "../includes/philo.h"

static void	sys_error(int num)
{
	if (num == MALLOC_ERR)
		ft_putendl_fd("philo: malloc failed", 2);
	else if (num == SEMOPEN_ERR)
		ft_putendl_fd("philo: opening semaphore failed", 2);
	else if (num == FORK_ERR)
		ft_putendl_fd("philo: fork fail: creating new proc failed", 2);
	else if (num == KILL_ERR)
		ft_putendl_fd("philo: killing process failed", 2);
	else if (num == THREAD_ERR)
		ft_putendl_fd("philo: creating death thread failed", 2);
}

static void	parser_err(int num)
{
	if (num == INV_ARG)
		ft_putendl_fd("philo: error: invalid number of arguments", 2);
	else if (num == NDGT_ERR)
		ft_putendl_fd("philo: error: non-digit character", 2);
	else if (num == NMAX_ERR)
		ft_putendl_fd("philo: error: number is more than int max", 2);
	else if (num == ZERO_ERR)
		ft_putendl_fd("philo: error: argument is equal to zero", 2);
}

void	print_msg(int type, int num)
{
	ft_putstr_fd(BOLDRED, 2);
	if (type == SYS_ERR)
		sys_error(num);
	else if (type == PAR_ERR)
		parser_err(num);
	ft_putstr_fd(RESET, 2);
}
