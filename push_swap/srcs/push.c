/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:17 by grusso            #+#    #+#             */
/*   Updated: 2021/06/14 16:42:01 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long *ft_intjoin(int dim, long *stack1, long *stack2)
{
	int	i;
	int j;
	int len;
	long tmp[dim];

	i = -1;
	while (++i < dim)
		tmp[i] = stack1[i];
	free(stack1);
	dim++;
	stack1 = (long *)ft_calloc(dim, sizeof(long));
	if (!stack1)
		return (NULL);
	len = dim;
	i = 1;
	j = 0;
	while (i < dim)
	{
		stack1[i] = tmp[j];
		i++;
		j++;
	}
	stack1[0] = stack2[0];
	return (stack1);
}

long *ft_intremove(int dim, long *stack)
{
	int	i;
	int j;
	long tmp2[dim];

	i = -1;
	while (++i < dim)
		tmp2[i] = stack[i];
	free(stack);
	dim--;
	if (dim > 0)
	{
		stack = (long *)ft_calloc(dim, sizeof(long));
		if (!stack)
			return (NULL);
		i = 0;
		j = 1;
		while (i < dim)
		{
			stack[i] = tmp2[j];
			i++;
			j++;
		}
	}
	return (stack);
}

void	ft_pa(t_stack *stack)
{
	int	i;
	int j;
	int	len;
	long tmp2[stack->len_b];

	stack->a = ft_intjoin(stack->len_a, stack->a, stack->b);
	stack->len_a++;
	stack->b = ft_intremove(stack->len_b, stack->b);
	stack->len_b--;


	puts("NEW STACK A");
	int k = -1;
	while (++k < stack->len_a)
		printf("%ld\n", stack->a[k]);
	puts("NEW STACK B");
	k = -1;
	while (++k < stack->len_b)
		printf("%ld\n", stack->b[k]);
}