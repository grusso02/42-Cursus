NAME =	philo

PAR =	1 800 200 200
FLAGS =	-Wall -Werror -Wextra

SRCS =	$(shell find . -name '*.c')
FILES =	$(shell find . -name '*.c' -name '*.h')

OBJ =	$(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME) -lpthread

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(PAR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all norme leaks clean fclean re
