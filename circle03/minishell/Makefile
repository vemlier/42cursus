# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junkpark <junkpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 10:31:15 by chukim            #+#    #+#              #
#    Updated: 2022/08/04 20:51:54 by junkpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft
INCLUDES = -I /usr/include \
           -I ./libft \
           -I .
LIBS     = -L /usr/lib/x86_64-linux-gnu \
           -lreadline \
           -lhistory \
           -ltermcap \
           -L ./libft -lft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar rcs
RM = rm -f

SRCS = main.c \
       ./builtins/echo.c \
       ./builtins/export.c \
       ./builtins/export_utils.c \
       ./builtins/unset.c \
       ./builtins/cd.c \
       ./builtins/env.c \
       ./builtins/pwd.c \
       ./builtins/exit.c \
       ./cmd/cmd.c \
       ./cmd/cmd_utils.c \
       ./env/env.c \
       ./env/env_utils.c \
       ./exec/exec.c \
       ./exec/exec_utils.c \
       ./exec/exec_wait.c \
       ./exec/path_utils.c \
       ./exec/pipe_utils.c \
       ./exec/redirect_utils.c \
       ./exec/run_utils.c \
       ./exec/file_utils.c \
       ./heredoc/heredoc.c \
       ./heredoc/heredoc_utils.c \
       ./heredoc/unlink.c \
       ./parser/parse.c \
       ./parser/parse_utils.c \
       ./parser/token_utils.c \
       ./parser/expand.c \
       ./parser/expand_utils.c \
       ./parser/big_utils.c \
       ./utils/signal.c \
       ./utils/error.c \
       ./utils/free.c \
       ./utils/print.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

all: $(NAME)

clean:
	make -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
