# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 07:49:30 by chukim            #+#    #+#              #
#    Updated: 2022/11/30 15:03:33 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	converter
SRCS		=	main.cpp \
				Converter.cpp
OBJS		=	$(SRCS:.cpp=.o)
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

%.o : %.cpp
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

# ------------------------------------- TESTS ---------------------------------

test1: $(NAME)
	./$(NAME) 0

test2: $(NAME)
	./$(NAME) nan

test3: $(NAME)
	./$(NAME) 42.0f

.PHONY:	all clean fclean re test1 test2 test3