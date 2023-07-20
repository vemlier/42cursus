# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 09:31:49 by chukim            #+#    #+#              #
#    Updated: 2023/07/19 11:34:48 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	btc
SRCS		=	main.cpp \
				BitcoinExchange.cpp
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