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
INCLUDES	= -Iincludes -I. -I./minilibx
RM			= rm -f
AR			= ar
ARFLAGS		= rcs
SRCS		= ./srcs/so_long.c ./srcs/image.c ./srcs/key.c \
			  ./srcs/map.c ./srcs/so_long_utils.c \
			  ./srcs/get_next_line.c ./srcs/get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)
LIBC		= ar rc

UNAME_S := $(shell uname -s)

# Compiler and linker options for macOS
ifeq ($(UNAME_S), Darwin)
	LDFLAGS = -Llibft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit
# Compiler and linker options for Linux
else
	LDFLAGS = -Llibft -lft -L./minilibx -lmlx -L/usr/lib/X11 -lX11 -lXext -L/usr/lib -lGL
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT)/
	make -C ./minilibx
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
	make clean -C ./minilibx

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)
	make clean -C ./minilibx

re : fclean all

.PHONY : all clean fclean re bonus
