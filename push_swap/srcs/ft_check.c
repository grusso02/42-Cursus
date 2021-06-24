/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:44:40 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:13:31 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	find_max(t_stack *stack)
{
	long	max;
	int i;

	max = stack->b[0];
	i = 0;
	while (++i < stack->len_b)
	{
		if (stack->b[i] > max)
			max = stack->b[i];
	}
	return (max);
}

long	find_max_a(t_stack *stack)
{
	long	max;
	int i;

	max = stack->a[0];
	i = 0;
	while (++i < stack->len_a)
	{
		if (stack->a[i] > max)
			max = stack->a[i];
	}
	return (max);
}

long	find_min(t_stack *stack)
{
	long	min;
	int i;

	min = stack->a[0];
	i = 0;
	while (++i < stack->len_a)
	{
		if (stack->a[i] < min)
			min = stack->a[i];
	}
	return (min);
}

void	pass_min_zero_pos(t_stack *stack)
{
	long min;

	min = find_min(stack);
	while (stack->a[0] > min)
	{
		if (min == stack->a[1])
			ft_sa(stack, PRINT);
		else if (min == stack->a[stack->len_a - 1])
			ft_rra(stack, PRINT);
		else
			ft_ra(stack, PRINT);
	}
}

void	ft_check(t_stack *stack)
{
	while (stack->len_a > 3)
	{
		pass_min_zero_pos(stack);
		ft_pb(stack, PRINT);
	}
	sort_three(stack);
	while (stack->len_b > 0)
		ft_pa(stack, PRINT);
	free_all(stack);
	exit (0);
}