/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:19:40 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/14 16:45:44 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parser(char *argv[], t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9')
					&& (argv[i][j + 1] == 45 || argv[i][j + 1] == 43))
				return (1);
			else if ((argv[i][j] == 45 || argv[i][j] == 43)
					&& (argv[i][j + 1] == 32 || !argv[i][j + 1]))
				return (1);
			else if ((argv[i][j] < '0' || argv[i][j] > '9') && (argv[i][j] != 32
					&& argv[i][j] != 45 && argv[i][j] != 43))
				return (1);
			j++;
		}
		i++;
	}
	stack->a = (long *)ft_calloc(word_counter(argv, ' '), sizeof(long));
	if (!stack->a)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	stack.b = (long *)ft_calloc(4, sizeof(long));
	stack.b[0] = 5;
	stack.b[1] = 6;
	stack.b[2] = 7;
	stack.b[3] = 8;
	stack.len_b = 4;
	puts("STACK A");
	if (argc < 2)
		ft_putstr_fd("\n", 0);
	else if (parser(argv, &stack) || pass_stack_a(argv, &stack))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	puts("STACK B");
	int k = -1;
	while (++k < stack.len_b)
		printf("%ld\n", stack.b[k]);
	ft_pa(&stack);

	free(stack.a);
	free(stack.b);
	return (0);
}
