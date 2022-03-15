NAME =		ft_containers

CXX	=		clang++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =		main.cpp
OBJ =		$(SRCS:.cpp=.o)

all : $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(NAME): $(OBJ)
	@$(CXX) $(CXXLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re