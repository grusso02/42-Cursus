/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 20:00:52 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:19:56 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	check(t_stack *stack)
{
	if (!stack->a || stack->b)
		ft_putstr_fd("KO\n", 1);
	else if (ft_check_order(stack, stack->len_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	exec_operations(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "sa"))
		ft_sa(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "sb"))
		ft_sb(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "ss"))
		ft_ss(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "ra"))
		ft_ra(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "rb"))
		ft_rb(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "rr"))
		ft_rr(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "rra"))
		ft_rra(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "rrb"))
		ft_rrb(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrr(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "pa"))
		ft_pa(stack, NOT_PRINT);
	else if (!ft_strcmp(line, "pb"))
		ft_pb(stack, NOT_PRINT);
	else
		return (1);
	return (0);
}

void	read_operations(t_stack *stack)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (exec_operations(stack, line))
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			exit (0);
		}
		free(line);
	}
	if (line)
		free(line);
}

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
	read_operations(&stack);
	check(&stack);
	free_all(&stack);
	return (0);
}