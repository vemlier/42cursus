# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 09:34:51 by chukim            #+#    #+#              #
#    Updated: 2022/07/07 10:54:55 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
INCLUDES	= -Iincludes
AR		= ar
ARFLAGS	= rcs
SRCS	= src/main.c \
		src/print_error.c
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(PRINTFDIR)
	cp $(PRINTFDIR)/$(PRINTFFILE) $@
	$(AR) $(ARFLAGS) $@ $?
	$(CC) -o $(NAME)_exec $(NAME)
	$(RM) $(NAME)
	mv $(NAME)_exec $(NAME)

clean :
	rm -f $(OBJS)
	make clean -C $(PRINTFDIR)

fclean : clean
	rm  -f $(NAME)
	make fclean -C $(PRINTFDIR)

re :
	make fclean
	make all

.PHONY	:	all clean fclean re