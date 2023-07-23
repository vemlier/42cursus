CXX           :=  c++
CXXFLAGS      :=  -Wall -Werror -Wextra -std=c++98
LDFLAGS       :=  
RM            :=  rm -f

NAME          :=  ircbot

SRCS_DIR      :=  srcs
SRCS          :=  main.cpp bot.cpp
SRCS          :=  $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS          :=  $(SRCS:.cpp=.o)

INCS_DIR      :=  includes

.PHONY        :  all
all           :  $(NAME)

$(NAME)       :  $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o           :  %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCS_DIR) -c $< -o $@

.PHONY        :  clean
clean         :
	$(RM) $(OBJS)

.PHONY        :  fclean
fclean        :  clean
	$(RM) $(NAME)
	
.PHONY        :  re
re            :
	make fclean
	make all