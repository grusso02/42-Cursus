/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:29:23 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:31:44 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack *stack, int n)
{
	long	tmp;
	int		i;

	if (!stack->a)
		return ;
	i = 0;
	tmp = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	stack->moves++;
	if (n == PRINT)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack *stack, int n)
{
	long	tmp;
	int		i;

	if (!stack->b)
		return ;
	i = 0;
	tmp = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	stack->moves++;
	if (n == PRINT)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack *stack, int n)
{
	if (!stack->a && !stack->b)
		return ;
	ft_ra(stack, NOT_PRINT);
	ft_rb(stack, NOT_PRINT);
	stack->moves--;
	if (n == PRINT)
		ft_putstr_fd("rr\n", 1);
}