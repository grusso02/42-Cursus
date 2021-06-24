/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:30:03 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:32:12 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack *stack, int n)
{
	long	tmp;
	int		i;
	int		len;

	if (!stack->a)
		return ;
	i = 0;
	len = stack->len_a;
	tmp = stack->a[stack->len_a - 1];
	while (i < stack->len_a - 1)
	{
		stack->a[len - 1] = stack->a[len - 2];
		i++;
		len--;
	}
	stack->a[0] = tmp;
	stack->moves++;
	if (n == PRINT)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *stack, int n)
{
	long	tmp;
	int		i;
	int		len;

	if (!stack->b)
		return ;
	i = 0;
	len = stack->len_b;
	tmp = stack->b[stack->len_b - 1];
	while (i < stack->len_b - 1)
	{
		stack->b[len - 1] = stack->b[len - 2];
		i++;
		len--;
	}
	stack->b[0] = tmp;
	stack->moves++;
	if (n == PRINT)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *stack, int n)
{
	if (!stack->a && !stack->b)
		return ;
	ft_rra(stack, NOT_PRINT);
	ft_rrb(stack, NOT_PRINT);
	stack->moves--;
	if (n == PRINT)
		ft_putstr_fd("rrr\n", 1);
}