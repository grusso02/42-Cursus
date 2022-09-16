/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:19:40 by gabriele          #+#    #+#             */
/*   Updated: 2022/08/08 15:58:05 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2)
		return (1);
	init_var(&stack);
	if (parser(argv, &stack) || pass_stack_a(argv, &stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_all(&stack);
		return (1);
	}
	if (ft_check_order(&stack, stack.len_a))
	{
		free_all(&stack);
		return (0);
	}
	if (stack.len_a <= 3)
		sort_three(&stack);
	else if (stack.len_a > 3 && stack.len_a < 500)
		ft_sort(&stack, 5);
	else if (stack.len_a >= 500)
		ft_sort(&stack, 11);
	free_all(&stack);
	return (0);
}
