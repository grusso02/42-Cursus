/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:18:08 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:14:59 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void bring_back(t_stack *stack)
{
	int half_len;
	int i;
	long check;

	i = -1;
	half_len = stack->len_b / 2;
	check = find_max(stack);
	while (++i < stack->len_b)
	{
		if (stack->b[i] == check)
			break ;
	}
	while (stack->b[0] < check)
	{
		if (i == 1)
			ft_sb(stack, PRINT);
		else if (i <= half_len)
			ft_rb(stack, PRINT);
		else if (i > half_len)
			ft_rrb(stack, PRINT);
	}
}

int count_min(t_stack *stack, long check)
{
	int i;

	i = -1;
	while (++i < stack->len_a)
	{
		if (stack->a[i] < check)
			return (1);
	}
	return (0);
}

void	move_to_top(t_stack *stack, int i, int half_len)
{
	if (i <= half_len)
	{
		if (stack->len_b > 1 && stack->b[0] != find_max(stack))
			ft_rr(stack, PRINT);
		else
			ft_ra(stack, PRINT);
	}
	else if (i > half_len)
	{
		if (stack->len_b > 1 && stack->b[0] != find_max(stack))
			ft_rrr(stack, PRINT);
		else
			ft_rra(stack, PRINT);
	}
}

void	ft_sort2(t_stack *stack, int min, int c_size, int c_num)
{
	int     half_len;
	int     i;

	while (count_min(stack, min + c_size * c_num) > 0)
	{
		i = -1;
		half_len = stack->len_a / 2;
		while (++i < stack->len_a)
		{
			if (stack->a[i] < min + c_size * c_num)
				break ;
		}
		while (stack->a[0] >= min + c_size * c_num)
			move_to_top(stack, i, half_len);
		if (stack->len_a == 0)
			break ;
		ft_pb(stack, PRINT);
	}
}

void	ft_sort(t_stack *stack, int div)
{
	int		min;
	int		max;
	int		c_size;
	int		c_num;

	if (stack->len_a <= ORDER)
		ft_check(stack);
	min = find_min(stack);
	max = find_max_a(stack);
	c_size = ((max - min) / div) + 1;
	c_num = 1;
	while (c_num <= div)
	{
		ft_sort2(stack, min, c_size, c_num);
		c_num++;
	}
	while (stack->len_b > 0)
	{
		bring_back(stack);
		ft_pa(stack, PRINT);
	}
}