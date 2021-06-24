/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:12:58 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 12:21:51 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_order(t_stack *stack, int n)
{
    if (n == 1 || n == 0)
        return (1);
    if (stack->a[n - 1] < stack->a[n - 2])
        return (0);
    return (ft_check_order(stack, n - 1));
}

void	init_var(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->len_a = 0;
	stack->len_b = 0;
	stack->moves = 0;
}

int	parser2(char *argv[])
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
	return (0);
}

int	parser(char *argv[], t_stack *stack)
{
	if (parser2(argv))
		return (1);
	stack->a = (long *)ft_calloc(word_counter(argv, ' '), sizeof(long));
	if (!stack->a)
		return (1);
	return (0);
}

void	free_all(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
}