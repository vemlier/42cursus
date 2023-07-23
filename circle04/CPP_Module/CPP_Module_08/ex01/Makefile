# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:38:45 by chukim            #+#    #+#              #
#    Updated: 2022/11/30 15:17:16 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex01
SRCS		=	main.cpp \
				span.cpp
OBJS		=	$(SRCS:.cpp=.o)
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re:
	make fclean
	make all

.PHONY:	all clean fclean re