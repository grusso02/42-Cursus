NAME =	megaphone

FLAGS =	-Wall -Werror -Wextra

SRCS =	$(shell find . -name '*.cpp')

OBJ =	$(SRCS:.cpp=.o)
CC	=	clang++

$(NAME): $(OBJ)
	@$(CC) $(SRCS) -o $(NAME)

all : $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re