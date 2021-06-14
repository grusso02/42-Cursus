/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:32:40 by grusso            #+#    #+#             */
/*   Updated: 2021/06/13 20:30:23 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack *stack)
{
	long	tmp;

	if (!stack->a)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
}

void	ft_sb(t_stack *stack)
{
	long	tmp;

	if (stack->b)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
}

void	ft_ss(t_stack *stack)
{
	if (!stack->a && !stack->b)
		return ;
	ft_sa(stack);
	ft_sb(stack);
}

void	ft_pa(t_stack *stack)
{
	int	i;
	int	len;
	long tmp[stack->len_b];
	int j;

	i = 0;
	stack->a[stack->len_a] = (long)ft_calloc(1, sizeof(long));
	len = ++stack->len_a;
	while (i < stack->len_a - 1)
	{
		stack->a[len - 1] = stack->a[len - 2];
		len--;
		i++;
	}
	stack->a[0] = stack->b[0];
	i = -1;
	while (++i < stack->len_b)
		tmp[i] = stack->b[i];
	free(stack->b);
	stack->len_b--;
	stack->b = (long *)ft_calloc(stack->len_b, sizeof(long));
	i = 0;
	j = 1;
	while (i < stack->len_b)
	{
		stack->b[i] = tmp[j];
		i++;
		j++;
	}



	puts("NEW STACK A");
	int k = -1;
	while (++k < stack->len_a)
		printf("%ld\n", stack->a[k]);
	puts("NEW STACK B");
	k = -1;
	while (++k < stack->len_b)
		printf("%ld\n", stack->b[k]);
}

void	ft_ra(t_stack *stack)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
}

void	ft_rb(t_stack *stack)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
}

void	ft_rr(t_stack *stack)
{
	if (!stack->a && !stack->b)
		return ;
	ft_ra(stack);
	ft_rb(stack);
}

void	ft_rra(t_stack *stack)
{
	long	tmp;
	int		i;
	int		len;

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
}

void	ft_rrb(t_stack *stack)
{
	long	tmp;
	int		i;
	int		len;

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
}

void	ft_rrr(t_stack *stack)
{
	if (!stack->a && !stack->b)
		return ;
	ft_rra(stack);
	ft_rrb(stack);
}