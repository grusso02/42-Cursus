NAME_FT =		ft_containers
NAME_STL =		stl_containers

CXX	=		clang++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS_FT =		ft_main.cpp
SRCS_STL =		stl_main.cpp

OBJ_FT =		$(SRCS_FT:.cpp=.o)
OBJ_STL =		$(SRCS_STL:.cpp=.o)

all : $(NAME_FT) $(NAME_STL)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(NAME_FT): $(OBJ_FT)
	@$(CXX) $(CXXLAGS) -o $(NAME_FT) $(OBJ_FT)

$(NAME_STL): $(OBJ_STL)
	@$(CXX) $(CXXLAGS) -o $(NAME_STL) $(OBJ_STL)

clean:
	@rm -rf $(OBJ_FT) $(OBJ_STL)

fclean: clean
	@rm -rf $(NAME_FT) $(NAME_STL)

re : fclean all

.PHONY: all clean fclean re