# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <grusso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 13:38:06 by grusso            #+#    #+#              #
#    Updated: 2021/02/06 19:16:40 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_printf_check.c \
			  ft_printf_check2.c \
			  ft_data_processing.c \
			  ft_processing_chr.c \
			  ft_processing_str.c \
			  ft_str_utils.c \
			  ft_processing_int.c \
			  ft_utils_int.c \
			  ft_processing_pointer.c \

CC			= gcc 

FLAGS		= -c -Wall -Werror -Wextra

OBJS		= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./includes
	cp includes/mylib.a $(NAME)
	CC $(FLAGS) -I ./ $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C ./includes
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./includes
	rm -rf $(NAME)

re: fclean all