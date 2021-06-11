/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:25:28 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/11 12:54:35 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		word_counter(char *argv[], char c)
{
	int		i;
    int     j;
	int		wcount;
	int		trigger;

	i = 0;
	wcount = 0;
	while (argv[i])
	{
        trigger = 0;
        j = 0;
        while (argv[i][j])
        {
            if (c == argv[i][j])
                trigger = 0;
            else if (trigger == 0)
            {
                trigger = 1;
                wcount++;
            }
            j++;
        }
        i++;
	}
	return (wcount - 1);
}

int check_double(t_stack *stack, int len)
{
    int i;
    int j;

    i = 0;
    while (i <= len / 2)
    {
        j = i + 1;
        while (j <= len)
        {
            if (stack->a[i] == stack->a[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int pass_stack_a(char *argv[], t_stack *stack)
{
    int i;
    int j;
    int k;
    int sign;

    stack->a = (int *)malloc(sizeof(int) * word_counter(argv, ' '));
    if (!stack->a)
        return (1);
    i = 0;
    k = 0;
    sign = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == '-')
                sign = -1;
            if ((argv[i][j] >= '0' && argv[i][j] <= '9'))
            {
                stack->a[k] = ((stack->a[k] * 10) + argv[i][j] - '0');
                if (argv[i][j + 1] == ' ' || !argv[i][j + 1])
                {
                    stack->a[k] *= sign;
                    sign = 1;
                    k++;
                }
            }
            j++;
        }
        i++;
    }
    if (check_double(stack, word_counter(argv, ' ')))
        return (1);
    k = -1;
    while (++k <= word_counter(argv, ' ') - 1)
        printf("%d\n", stack->a[k]);
    return (0);
}