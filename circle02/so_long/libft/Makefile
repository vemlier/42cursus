# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 14:06:01 by chukim            #+#    #+#              #
#    Updated: 2022/10/29 16:45:50 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = rcs
INCLUDES = ./includes/libft.h
SRCS = ./srcs/ft_isalpha.c ./srcs/ft_isdigit.c ./srcs/ft_isalnum.c ./srcs/ft_isascii.c ./srcs/ft_isprint.c \
		./srcs/ft_strlen.c ./srcs/ft_memset.c ./srcs/ft_bzero.c ./srcs/ft_memcpy.c ./srcs/ft_memmove.c \
		./srcs/ft_strlcpy.c ./srcs/ft_strlcat.c ./srcs/ft_toupper.c ./srcs/ft_tolower.c ./srcs/ft_strchr.c \
		./srcs/ft_strrchr.c ./srcs/ft_strncmp.c ./srcs/ft_memchr.c ./srcs/ft_memcmp.c ./srcs/ft_strnstr.c \
		./srcs/ft_atoi.c ./srcs/ft_calloc.c ./srcs/ft_strdup.c ./srcs/ft_substr.c ./srcs/ft_strjoin.c \
		./srcs/ft_strtrim.c ./srcs/ft_split.c ./srcs/ft_itoa.c ./srcs/ft_strmapi.c ./srcs/ft_striteri.c \
		./srcs/ft_putchar_fd.c ./srcs/ft_putstr_fd.c ./srcs/ft_putendl_fd.c ./srcs/ft_putnbr_fd.c
BONUS_SRCS = ./srcs/ft_lstnew.c ./srcs/ft_lstadd_front.c ./srcs/ft_lstsize.c ./srcs/ft_lstlast.c \
		./srcs/ft_lstadd_back.c ./srcs/ft_lstdelone.c ./srcs/ft_lstclear.c ./srcs/ft_lstiter.c ./srcs/ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef FLAG_BONUS
OBJS += $(BONUS_OBJS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

bonus :
	make FLAG_BONUS=1 all

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus