NAME =	Account

FLAGS =	-Wall -Werror -Wextra

#SRCS =	$(shell find . -name '*.cpp')
SRCS = main.cpp Zombie.cpp

OBJ =	$(SRCS:.cpp=.o)
CC	=	clang++

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re