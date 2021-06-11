/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:26:32 by gabriele          #+#    #+#             */
/*   Updated: 2021/05/31 15:40:50 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exp_do(t_scanner *scan)
{
	scan->j = 0;
	scan->trigger = 0;
	while (scan->arg[scan->j] && !scan->trigger)
	{
		if (scan->arg[scan->j] == '=')
			scan->trigger = 1;
		scan->j++;
	}
	scan->j = 0;
	if (scan->trigger == 1)
	{
		while (scan->env[scan->j])
			scan->j++;
		free(scan->env[scan->j]);
		scan->env[scan->j] = ft_strdup(scan->exp[scan->i]);
		scan->env[scan->j + 1] = 0;
	}
	scan->i++;
}

void	ft_export2(t_scanner *scan)
{
	scan->i = 0;
	scan->trigger = 0;
	while (scan->arg[scan->i] && !scan->trigger)
	{
		if (scan->arg[scan->i] == '=')
			scan->trigger = 1;
		scan->i++;
	}
	scan->i = 0;
	if (scan->trigger == 1)
	{
		while (scan->env[scan->i])
			free(scan->env[scan->i]);
		scan->env[scan->i] = ft_strdup(scan->arg);
		scan->env[scan->i + 1] = 0;
	}
}

int	ft_export(t_scanner *scan)
{
	scan->i = 0;
	while (scan->arg_exec[scan->i])
		scan->i++;
	scan->exp = (char **)malloc(sizeof(char *) * scan->i + 1);
	scan->i = 0;
	while (scan->arg_exec[scan->i])
	{
		scan->exp[scan->i] = ft_strdup(scan->arg_exec[scan->i]);
		scan->i++;
	}
	scan->exp[scan->i] = 0;
	scan->i = 0;
	if (scan->exp)
	{
		while (scan->exp[scan->i])
			ft_exp_do(scan);
	}
	else
		ft_export2(scan);
	scan->i = 0;
	while (scan->exp[scan->i])
		free(scan->exp[scan->i++]);
	free(scan->exp);
	return (scan->ret = 0);
}
