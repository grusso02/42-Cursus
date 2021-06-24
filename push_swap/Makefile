NAME_PS = push_swap
NAME_CK = checker

SRCS_PS = srcs/ft_check.c srcs/ft_sort.c srcs/main.c \
		srcs/sort_three.c

SRCS_CK = check/checker.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

SRCS_SH = share/pass_stack_a.c share/utils.c \
		share/push.c share/rotate_inv.c \
		share/rotate.c share/swap.c

LIBFT = libft/libft.a

GCC_FLAG = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAG)

OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CK = $(SRCS_CK:.c=.o)
OBJS_SH = $(SRCS_SH:.c=.o)

all: $(NAME_PS) $(NAME_CK)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_PS):
	make bonus -C ./libft
	$(CC) $(SRCS_PS) $(SRCS_SH) $(LIBFT) -o $(NAME_PS) -g

$(NAME_CK):
	make bonus -C ./libft
	$(CC) $(SRCS_CK) $(SRCS_SH) $(LIBFT) -o $(NAME_CK) -g

clean:
	rm -f $(OBJS_PS) $(OBJS_CK) $(OBJS_SH)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME_PS) $(NAME_CK)
	make fclean -C ./libft

re: fclean all

.PHONY: fclean all