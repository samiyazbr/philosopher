# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 18:32:36 by ommohame          #+#    #+#              #
#    Updated: 2022/10/13 08:51:03 by ommohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philo_bonus

SRCS		=		main.c				\
					parser.c			\
					error_msg.c			\
					init_struct.c		\
					init_philo.c		\
					terminate_proc.c	\
					life_cycle.c		\
					tasks.c				\
					time.c				\
					log_msg.c			\

UTILS		=		ft_put_fd.c			\
					ft_isdigit.c		\
					ft_atox.c			\

SRCS_DIR	=		./srcs/

UTILS_DIR	=		./utils/

INCLUDES	=		./includes

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra -pthread -g3

OBJS		=		$(addprefix $(SRCS_DIR),$(SRCS:.c=.o))

UTILS_OBJS	=		$(addprefix $(UTILS_DIR),$(UTILS:.c=.o))

RM			=		rm -rf

$(NAME)		:		$(UTILS_OBJS) $(OBJS)
					$(CC) $(CFLAGS) $(UTILS_OBJS) $(OBJS) -I$(INCLUDES) -o $(NAME)
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