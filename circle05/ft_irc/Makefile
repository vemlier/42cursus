CXX           :=  c++
CXXFLAGS      :=  -Wall -Werror -Wextra -std=c++98
LDFLAGS       :=  
RM            :=  rm -f

NAME          :=  ircserv

COMMANDS_DIR  :=  commands
COMMANDS_SRCS :=  CommandHandler.cpp \
                  JoinCommand.cpp PartCommand.cpp \
                  PrivMsgCommand.cpp NoticeCommand.cpp \
                  PingCommand.cpp PongCommand.cpp \
                  NickCommand.cpp UserCommand.cpp \
                  ModeCommand.cpp PassCommand.cpp \
                  KickCommand.cpp QuitCommand.cpp

COMMANDS_SRCS :=  $(addprefix $(COMMANDS_DIR)/, $(COMMANDS_SRCS))

SRCS_DIR      :=  srcs
SRCS          :=  main.cpp Server.cpp Client.cpp Channel.cpp \
                  $(COMMANDS_SRCS)
SRCS          :=  $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS          :=  $(SRCS:.cpp=.o)

INCS_DIR      :=  includes
BOT_DIR       :=  bot

.PHONY        :  all
all           :  $(NAME)
	make -j -C $(BOT_DIR) all

$(NAME)       :  $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o           :  %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCS_DIR) -c $< -o $@

.PHONY        :  bot
bot           :
	make -j -C $(BOT_DIR) all

.PHONY        :  clean
clean         :
	$(RM) $(OBJS)
	make -C $(BOT_DIR) clean

.PHONY        :  fclean
fclean        :  clean
	$(RM) $(NAME)
	make -C $(BOT_DIR) fclean

.PHONY        :  re
re            :
	make fclean
	make -j all
