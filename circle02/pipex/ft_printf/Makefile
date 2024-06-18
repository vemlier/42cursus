# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 11:18:20 by chukim            #+#    #+#              #
#    Updated: 2022/12/02 02:56:12 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
INCLUDES	= -Iincludes
SRCS		= ./srcs/main.c \
				./srcs/ft_printf_parse.c \
				./srcs/ft_printf_char.c \
				./srcs/ft_printf_string.c \
				./srcs/ft_printf_num.c \
				./srcs/ft_printf_num_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $@
	$(AR) $(ARFLAGS) $@ $?

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR) 

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	
re:
	make fclean
	make all

.PHONY: all clean fclean re