# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 14:23:28 by chukim            #+#    #+#              #
#    Updated: 2022/11/30 11:48:45 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	replace
SRCS		=	main.cpp 
OBJS		=	$(SRCS:.cpp=.o)
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
FILES		=	test.replace

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(FILES)
	
re:	
	make fclean 
	make all

test: all
	./$(NAME) test a b

.PHONY:	all clean fclean re test