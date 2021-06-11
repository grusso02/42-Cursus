/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:19:40 by gabriele          #+#    #+#             */
/*   Updated: 2021/06/11 18:02:19 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parser(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9')
					&& (argv[i][j + 1] == 45 || argv[i][j + 1] == 43))
				return (1);
			else if ((argv[i][j] == 45 || argv[i][j] == 43)
					&& (argv[i][j + 1] == 32 || !argv[i][j + 1]))
				return (1);
			else if ((argv[i][j] < '0' || argv[i][j] > '9') && (argv[i][j] != 32
						&& argv[i][j] != 45 && argv[i][j] != 43))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2)
		ft_putstr_fd("\n", 0);
	else if (parser(argv) || pass_stack_a(argv, &stack))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
