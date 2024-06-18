CXXFLAGS	:=  -Wall -Werror -Wextra -std=c++98
NAME	:=  ircserv
INCLUDES	= -Iincludes -I/usr/include/kqueue
LIBS	:=  -lkqueue
SRCS	:=	./srcs/commands/CommandHandler.cpp ./srcs/commands/JoinCommand.cpp ./srcs/commands/PartCommand.cpp\
		./srcs/commands/PrivMsgCommand.cpp ./srcs/commands/NoticeCommand.cpp ./srcs/commands/PingCommand.cpp\
		./srcs/commands/PongCommand.cpp ./srcs/commands/NickCommand.cpp ./srcs/commands/UserCommand.cpp\
		./srcs/commands/ModeCommand.cpp ./srcs/commands/PassCommand.cpp ./srcs/commands/KickCommand.cpp\
		./srcs/commands/QuitCommand.cpp ./srcs/main.cpp ./srcs/Server.cpp ./srcs/Client.cpp ./srcs/Channel.cpp
OBJS          :=  $(SRCS:.cpp=.o)
BOT_DIR       :=  bot

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LIBS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

bot :
	make -C $(BOT_DIR) all

clean :
	rm -f $(OBJS)
	make -C $(BOT_DIR) clean

fclean :  clean
	rm -f $(NAME)
	make -C $(BOT_DIR) fclean

re :
	make fclean
	make all

.PHONY : all bot clena fclean re