/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:32:40 by grusso            #+#    #+#             */
/*   Updated: 2021/06/24 13:16:26 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack *stack, int n)
{
	long	tmp;

	if (!stack->a)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	stack->moves++;
	if (n == PRINT)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *stack, int n)
{
	long	tmp;

	if (!stack->b)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	stack->moves++;
	if (n == PRINT)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *stack, int n)
{
	if (!stack->a && !stack->b)
		return ;
	ft_sa(stack, NOT_PRINT);
	ft_sb(stack, NOT_PRINT);
	if (n == PRINT)
		ft_putstr_fd("sb\n", 1);
}