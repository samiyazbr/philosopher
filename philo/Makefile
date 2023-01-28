
NAME		=		philo

SRCS		=		main.c				\
					print_msg.c 		\
					parser.c			\
					init_struct.c		\
					philo.c				\
					time.c				\
					log.c				\
					forks.c				\
					check_death.c		\
					free_table.c		\
					philo_state.c		\
					thread.c

UTILS		=		ft_fd.c				\
					ft_isdigit.c		\
					ft_atoi.c			\

SRCS_DIR	=		./srcs/

UTILS_DIR	=		./utils/

INCLUDE	=		./include

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra -pthread

OBJS		=		$(addprefix $(SRCS_DIR),$(SRCS:.c=.o))

UTILS_OBJS	=		$(addprefix $(UTILS_DIR),$(UTILS:.c=.o))

RM			=		rm -rf

$(NAME)		:		$(UTILS_OBJS) $(OBJS)
					$(CC) $(CFLAGS) $(UTILS_OBJS) $(OBJS) -I$(INCLUDE) -o $(NAME)
					clear
					@echo "Compilation  Successful!"

all			:		$(NAME)

clean		:
					@$(RM) $(OBJS) 
					@$(RM) $(UTILS_OBJS)

fclean		:		clean
					@$(RM) $(NAME)

re			:		fclean all

.PHONY		:		$(NAME) all clean fclean re