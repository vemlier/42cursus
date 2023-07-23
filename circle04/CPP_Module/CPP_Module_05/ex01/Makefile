# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chukim <chukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 11:22:21 by chukim            #+#    #+#              #
#    Updated: 2022/11/30 14:45:37 by chukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex01
SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp
OBJS		=	$(SRCS:.cpp=.o)
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re:
	make fclean
	make all

.PHONY:	all clean fclean re