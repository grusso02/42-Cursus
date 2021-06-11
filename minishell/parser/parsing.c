/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:34:50 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/31 15:11:03 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_space(t_scanner *scan)
{
	char	**str;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	str = scan->all_words3;
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			while (str[i][j] && ft_isspace(str[i][j]))
				j++;
			while (str[i][j] && !ft_isspace(str[i][j]))
				scan->all_words3[i][x++] = str[i][j++];
			scan->all_words3[i][x] = '\0';
			while (str[i][j] && ft_isspace(str[i][j]))
				j++;
		}
		i++;
	}
}

void	if_exec_other(t_scanner *scan, int not_cmd, int res)
{
	not_cmd = check_execve(scan);
	if (scan->global_exit == INVALID_CMD)
		exit_shell(scan->command, scan, res);
	free_format_cmd(scan);
}

void	built_in(int res, t_scanner *scan)
{
	if (res == ECHO1)
		ft_echo(scan);
	if (res == PWD)
		ft_pwd(scan);
	if (res == CD)
		ft_cd(scan);
	if (res == ENV)
		ft_env(scan);
	if (res == EXPORT)
		ft_export(scan);
	if (res == UNSET)
		ft_unset(scan);
	if (res == EXIT)
		exit_shell(scan->command, scan, res);
}

void	parse_cmd(int res, t_scanner *scan, char *cmd)
{
	int	not_cmd;

	not_cmd = -1;
	if (scan->valid_arg != INVALID_CMD && scan->redirect != REDIRECT_1 \
		&& scan->redirect != REDIRECT_2)
	{
		built_in(res, scan);
		if (res == INVALID_CMD)
		{
			not_cmd = check_execve(scan);
			if (scan->global_exit == INVALID_CMD)
				exit_shell(cmd, scan, res);
			free_format_cmd(scan);
		}
	}
	else if (scan->redirect != INVALID_CMD)
		if_exec_other(scan, not_cmd, res);
	else
		exit_shell(cmd, scan, QUOTES);
}

int	cmp_command(t_scanner *scan)
{
	if (ft_strcmp("cd", scan->command) == 0)
		return (CD);
	if (ft_strcmp("echo", scan->command) == 0)
		return (ECHO1);
	if (ft_strcmp("pwd", scan->command) == 0)
		return (PWD);
	if (ft_strcmp("export", scan->command) == 0)
		return (EXPORT);
	if (ft_strcmp("unset", scan->command) == 0)
		return (UNSET);
	if (ft_strcmp("env", scan->command) == 0)
		return (ENV);
	if (ft_strcmp("exit", scan->command) == 0)
		return (EXIT);
	return (scan->ret = INVALID_CMD);
}
