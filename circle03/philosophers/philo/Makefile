# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 11:50:43 by chukim            #+#    #+#              #
#    Updated: 2022/08/10 23:10:30 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = philosophers.c \
		preprocess.c \
		utils.c \
		action.c
OBJS = $(SRCS:%.c=%.o)

all	:	$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lpthread

clean	:
	rm -f $(OBJS)
		
fclean	:	clean
	rm -f $(NAME)
		
re	:	fclean all

.PHONY	:	all clean fclean re bonus