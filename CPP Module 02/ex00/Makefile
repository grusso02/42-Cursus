NAME =	Zombie

CC	=	clang++
FLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	$(shell find . -name '*.cpp')
OBJ =	$(SRCS:.cpp=.o)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re