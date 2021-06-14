/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:22:38 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/13 20:00:33 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    long    *a;
    long    *b;
    int     len_a;
    int     len_b;
}   t_stack;

int pass_stack_a(char *argv[], t_stack *stack);
int	word_counter(char *argv[], char c);
void	ft_pa(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rra(t_stack *stack);

#endif