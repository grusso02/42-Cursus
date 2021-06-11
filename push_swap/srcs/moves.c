/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:32:40 by grusso            #+#    #+#             */
/*   Updated: 2021/06/11 18:21:33 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(char *argv[], t_stack *stack)
{
	int tmp;

	if (word_counter(argv, ' ') >= 2)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
}

void	ft_sb(char *argv[], t_stack *stack)
{
	int tmp;

	if (word_counter(argv, ' ') >= 2)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
}

void	ft_ss(char *argv[], t_stack *stack)
{
	if (word_counter(argv, ' ') >= 2)
	{
		ft_sa(argv, stack);
		ft_sb(argv, stack);
	}
}
