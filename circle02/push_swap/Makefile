# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 12:46:09 by chukim            #+#    #+#              #
#    Updated: 2022/12/23 04:38:57 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBNAME		= push_swap.a
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rcs
INCLUDES	= -Iincludes
SRCS		= ./srcs/main.c ./srcs/parser.c ./srcs/stack_making.c ./srcs/stack_printing.c \
			./srcs/stack_basic.c ./srcs/stack_push_swap1.c ./srcs/stack_push_swap2.c ./srcs/stack_arr.c \
			./srcs/error.c ./srcs/sorting_a.c ./srcs/sorting_b.c ./srcs/quick_sorting.c \
			./srcs/main_sorting1.c ./srcs/main_sorting2.c ./srcs/sorting_5.c ./srcs/opt_op.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
		make -C $(PRINTFDIR)
		cp $(PRINTFDIR)/$(PRINTFFILE) $(LIBNAME)
		ar $(ARFLAGS) $(LIBNAME) $?
		$(CC) $(CFLAGS) -o $@ $(LIBNAME)

clean:
	rm -f $(OBJS)
	make -C $(PRINTFDIR) clean
		

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBNAME)
	make fclean -C $(PRINTFDIR)

re : clean all

.PHONY : all clean fclean re