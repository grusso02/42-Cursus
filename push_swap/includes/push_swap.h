/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:22:38 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/24 13:19:18 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define ORDER 5
# define PRINT 0
# define NOT_PRINT 1

typedef struct s_stack
{
	long    *a;
	long    *b;
	int     len_a;
	int     len_b;
	int     moves;
}   t_stack;

void	init_var(t_stack *stack);
int		parser(char *argv[], t_stack *stack);
int		pass_stack_a(char *argv[], t_stack *stack);
int		word_counter(char *argv[], char c);
void	ft_sa(t_stack *stack, int n);
void	ft_sb(t_stack *stack, int n);
void	ft_ss(t_stack *stack, int n);
void	ft_pa(t_stack *stack, int n);
void	ft_pb(t_stack *stack, int n);
void	ft_ra(t_stack *stack, int n);
void	ft_rb(t_stack *stack, int n);
void	ft_rr(t_stack *stack, int n);
void	ft_rra(t_stack *stack, int n);
void	ft_rrb(t_stack *stack, int n);
void	ft_rrr(t_stack *stack, int n);
int		ft_check_order(t_stack *stack, int b);
long	find_min(t_stack *stack);
long	find_max(t_stack *stack);
long	find_max_a(t_stack *stack);
void	sort_three(t_stack *stack);
void    ft_check(t_stack *stack);
void    ft_sort(t_stack *stack, int div);
void	free_all(t_stack *stack);

#endif