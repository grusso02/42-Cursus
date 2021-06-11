# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 16:03:13 by grusso            #+#    #+#              #
#    Updated: 2021/05/30 16:16:41 by dlanzilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a

SRCS = ./main.c \
	   ./utilities/utilities1.c ./RawMode/rawmode.c ./RawMode/rawmode2.c ./RawMode/rawmode3.c \
	   ./RawMode/die.c ./parser/split_string.c ./parser/free.c ./parser/command.c \
	   ./parser/quotes_counter.c ./parser/get_words.c ./parser/get_words2.c \
	   ./parser/conversion_cmd.c ./parser/args.c ./parser/all_str.c ./parser/redirect.c\
	   ./parser/parsing.c ./parser/execve.c ./parser/pipe.c ./parser/reverse_redirection.c\
	   ./parser/reverse_redirection2.c ./utilities/welcome.c ./builtins/echo.c ./builtins/pwd.c\
		./builtins/cd.c ./builtins/env.c ./builtins/export.c \
	   ./builtins/unset.c
LIBFT = libft/libft.a

GCC_FLAG = -Wall -Werror -Wextra -c
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: fclean all