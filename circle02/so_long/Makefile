# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 10:41:39 by chukim            #+#    #+#              #
#    Updated: 2022/10/29 16:47:32 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = rcs
SRCS		= ./srcs/so_long.c ./srcs/image.c ./srcs/key.c \
				./srcs/map.c ./srcs/so_long_utils.c \
				./srcs/get_next_line.c ./srcs/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
LIBC = ar rc

all : $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cc -o $(NAME) $(OBJS) -Llibft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus