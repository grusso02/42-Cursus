/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:42:24 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 16:49:14 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pipe_execve2(t_scanner *scan, int status, int z)
{
	z = 0;
	dup2(scan->fd2[0], STDIN_FILENO);
	close(scan->fd2[1]);
	close(scan->fd2[0]);
	while (status < 0 )
	{
		status = execve(scan->format_cmd[z], scan->piped2, scan->env);
		if (scan->format_cmd[z] == NULL && status < 0)
		{
			wait(NULL);
			scan->global_exit = INVALID_CMD;
			exit_shell(scan->piped[0], scan, INVALID_CMD);
		}
		z++;
	}
}

void	pipe_execve1(t_scanner *scan, int status)
{
	int	z;

	z = 0;
	status = -1;
	conversion_command(scan, scan->piped[0]);
	dup2(scan->fd2[1], STDOUT_FILENO);
	z = 0;
	close(scan->fd2[1]);
	close(scan->fd2[0]);
	while (status < 0)
	{
		status = execve(scan->format_cmd[z], scan->piped, scan->env);
		if (scan->format_cmd[z] == NULL && status < 0)
		{
			wait(NULL);
			scan->global_exit = INVALID_CMD;
			exit_shell(scan->piped[0], scan, INVALID_CMD);
		}
		z++;
	}
}

void	wait_pipe(t_scanner *scan, pid_t pid)
{
	int	a;

	close(scan->fd2[1]);
	close(scan->fd2[0]);
	waitpid(pid, &a, 0);
}

int	execve_pipe(t_scanner *scan, int i, int z, int status)
{
	pid_t	pid;

	pipe(scan->fd2);
	while (scan->all_words3[i + 2] != NULL)
		i++;
	pid = fork();
	scan->piped = ft_split(scan->all_words3[i], ' ');
	scan->piped2 = ft_split(scan->all_words3[i + 1], ' ');
	if (pid == 0)
		pipe_execve1(scan, status);
	else
	{
		conversion_command(scan, scan->piped2[0]);
		status = -1;
		pid = fork();
		if (pid == 0)
			pipe_execve2(scan, status, z);
		else
			wait_pipe(scan, pid);
	}
	close(scan->fd2[1]);
	close(scan->fd2[0]);
	return (status);
}

void	check_pipe(char *str, t_scanner *scan)
{
	int	i;

	i = 0;
	scan->count_pipe = 0;
	while (str[i])
		if (str[i++] == '|')
			scan->count_pipe++;
	if (scan->count_pipe > 0)
	{
		scan->all_words3 = ft_split(str, '|');
		execve_pipe(scan, 0, 0, -1);
	}
}
