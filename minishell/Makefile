.PHONY: libft minilibx

SRCS = ./main.c
	   ./GNL/get_next_line.c \
	   ./GNL/get_next_line_utils.c \
		

NAME = minishell

GCC_FLAG = -Wall -Werror -Wextra -g
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)


all:  $(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

clean:
	rm -f $(OBJS)
	

fclean: clean
	rm -f $(NAME)

re: fclean all