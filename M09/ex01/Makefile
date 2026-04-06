NAME    = RPN
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM      = rm -f

SRCS    = main.cpp src/RPN.cpp
OBJS    = $(SRCS:.cpp=.o)
INC     = -I inc

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
