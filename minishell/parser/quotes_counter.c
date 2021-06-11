/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:49:38 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 16:53:18 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_quotes_1(char *cmd)
{
	int	i;
	int	quotes;

	quotes = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '"')
			quotes++;
		i++;
	}
	return (quotes);
}

int	count_quotes_2(char *cmd)
{
	int	i;
	int	quotes;

	quotes = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39)
			quotes++;
		i++;
	}
	return (quotes);
}

void	if_wrong_quot(char *cmd, t_scanner *scan, int z)
{
	if (cmd[z] != 39)
	{
		scan->valid_arg = INVALID_CMD;
		exit_shell(cmd, scan, QUOTES);
	}
}

int	find_quot(t_scanner *scan, int z, int i, char *cmd)
{
	int	len;

	len = 0;
	z = i + 1;
	while (cmd[z] != '"')
	{
		len++;
		z++;
	}
	if (cmd[z] != '"')
	{
		scan->valid_arg = INVALID_CMD;
		exit_shell(cmd, scan, QUOTES);
	}
	return (len);
}
