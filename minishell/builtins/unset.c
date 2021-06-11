/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:26:54 by gabriele          #+#    #+#             */
/*   Updated: 2021/05/31 15:40:13 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset3(t_scanner *scan)
{
	scan->i = -1;
	while (scan->env[++scan->i] && !scan->trigger)
	{
		if (!ft_strncmp(scan->env[scan->i], scan->arg, ft_strlen(scan->arg)))
			scan->trigger = 1;
	}
	scan->i = scan->i - 1;
	if (scan->trigger == 1)
	{
		if ((scan->env[scan->i][(ft_strlen(scan->arg))]) == '=')
		{
			free(scan->env[scan->i]);
			while (scan->env[scan->i])
			{
				scan->env[scan->i] = scan->env[scan->i + 1];
				scan->i++;
			}
			scan->env[scan->i] = 0;
		}
	}
}

void	trigger(t_scanner *scan)
{
	if ((scan->env[scan->i]
			[(ft_strlen(scan->arg_exec[scan->j]))]) == '=')
	{
		free(scan->env[scan->i]);
		while (scan->env[scan->i])
		{
			scan->env[scan->i] = scan->env[scan->i + 1];
			scan->i++;
		}
		scan->env[scan->i] = 0;
	}
}

void	ft_unset2(t_scanner *scan)
{
	while (scan->arg_exec[scan->j])
	{
		scan->i = -1;
		scan->trigger = 0;
		while (scan->env[++scan->i] && !scan->trigger)
		{
			if (!ft_strncmp(scan->env[scan->i], scan->arg_exec[scan->j],
					ft_strlen(scan->arg_exec[scan->j])))
				scan->trigger = 1;
		}
		scan->i = scan->i - 1;
		if (scan->trigger == 1)
			trigger(scan);
		scan->j++;
	}
}

int	ft_unset(t_scanner *scan)
{
	scan->trigger = 0;
	if (scan->arg_exec)
	{
		scan->j = 0;
		while (scan->arg_exec[scan->j])
		{
			scan->j = 0;
			ft_unset2(scan);
		}
		scan->j = 0;
	}
	else
		ft_unset3(scan);
	return (scan->ret = 0);
}
