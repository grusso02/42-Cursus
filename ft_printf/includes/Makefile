# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <grusso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 13:38:06 by grusso            #+#    #+#              #
#    Updated: 2021/02/06 19:08:20 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mylib.a

SRCS		= ft_putchar.c \
			  ft_putstr.c \
			  ft_strlen.c \
			  ft_itoa.c \
			  ft_itoa_unsigned.c \
			  ft_itoa_base.c \
			  ft_strjoin.c \

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all