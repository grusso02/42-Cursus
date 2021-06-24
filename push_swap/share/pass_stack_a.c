/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:25:28 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/23 18:12:21 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	word_counter(char *argv[], char c)
{
	int	i;
	int	j;
	int	wcount;
	int	trigger;

	i = 0;
	wcount = 0;
	while (argv[i])
	{
		trigger = 0;
		j = 0;
		while (argv[i][j])
		{
			if (c == argv[i][j])
				trigger = 0;
			else if (trigger == 0)
			{
				trigger = 1;
				wcount++;
			}
			j++;
		}
		i++;
	}
	return (wcount - 1);
}

int	check_double(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a - 1)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (stack->a[i] == stack->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int pass_stack_a2(char *argv[], t_stack *stack, int i, int j, int k, int sign)
{
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				sign = -1;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				stack->a[k] = ((stack->a[k] * 10) + argv[i][j] - '0');
				if (stack->a[k] > 2147483647 && sign == 1)
					return (1);
				else if (stack->a[k] > 2147483648 && sign == -1)
					return (1);
				if (argv[i][j + 1] == ' ' || !argv[i][j + 1])
				{
					stack->a[k] *= sign;
					sign = 1;
					k++;
				}
			}
			j++;
		}
	}
	return (0);
}

int	pass_stack_a(char *argv[], t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	sign;

	i = -1;
	j = 0;
	k = 0;
	sign = 1;
	stack->len_a = word_counter(argv, ' ');
	if (pass_stack_a2(argv, stack, i, j, k, sign))
		return (1);
	if (check_double(stack))
		return (1);
	return (0);
}
