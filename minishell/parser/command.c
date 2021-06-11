/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:12:30 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 17:18:09 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_command3(t_scanner *scan, int i, int j, char *cmd)
{
	if (cmd[i] == '"' || cmd[i] == 39)
	{
		if (cmd[i] == '"')
		{
			while (cmd[i] == '"')
				i++;
			while (cmd[i] && cmd[i] != '"')
				scan->command[j++] = cmd[i++];
		}
		else
		{
			while (cmd[i] == 39)
				i++;
			while (cmd[i] && cmd[i] != 39)
				scan->command[j++] = cmd[i++];
		}
	}
	else
	{
		while (cmd[i] && cmd[i] != '\t' && cmd[i] != ' ')
			scan->command[j++] = cmd[i++];
	}
	scan->command[j] = '\0';
}

int	get_command2(t_scanner *scan, char *cmd, int z, int i)
{
	int	len;

	len = 0;
	if (cmd[i] == 39 || cmd[i] == '"')
	{
		if (cmd[i] == '"')
			len = find_quot(scan, z, i, cmd);
		else
		{
			z = i + 1;
			while (cmd[z] != 39)
			{
				len++;
				z++;
			}
			if_wrong_quot(cmd, scan, z);
		}
	}
	else
	{
		while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
			i++;
		len = i;
	}
	return (len);
}

void	get_command(t_scanner *scan, char *cmd)
{
	int	i;
	int	z;
	int	len;

	i = 0;
	z = 0;
	len = 0;
	if (count_quotes_1(cmd) % 2 == 0 && count_quotes_2(cmd) % 2 == 0)
	{
		while (cmd[i] == ' ' || cmd[i] == '\t' )
			i++;
		len = get_command2(scan, cmd, z, i);
		scan->command = malloc(sizeof(char *) * (len + 1));
		i = 0;
		while (cmd[i] == ' ' || cmd[i] == '\t')
			i++;
		get_command3(scan, i, 0, cmd);
	}
	else
	{
		scan->command = NULL;
		scan->valid_arg = INVALID_CMD;
		exit_shell(cmd, scan, QUOTES);
	}
}
