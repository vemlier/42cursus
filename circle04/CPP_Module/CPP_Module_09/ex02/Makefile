# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 10:02:10 by chukim            #+#    #+#              #
#    Updated: 2023/07/19 11:35:25 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe
SRCS		=	main.cpp \
				PmergeMe.cpp
OBJS		=	$(SRCS:.cpp=.o)
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

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
