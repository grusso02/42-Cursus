/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:57:35 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:19:41 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->a[0];
	second = stack->a[1];
	third = stack->a[2];
	if ((first > second) && (second > third) && (third < first))
	{
		ft_sa(stack, PRINT);
		ft_rra(stack, PRINT);
	}
	else if ((first > second) && (second < third) && (third < first))
		ft_ra(stack, PRINT);
	else if ((first > second) && (second < third) && (third > first))
		ft_sa(stack, PRINT);
	else if ((first < second) && (second > third) && (third < first))
		ft_rra(stack, PRINT);
	else if ((first < second) && (second > third) && (third > first))
	{
		ft_rra(stack, PRINT);
		ft_sa(stack, PRINT);
	}
}