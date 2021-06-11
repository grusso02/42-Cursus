/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:46:47 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/31 15:56:11 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execve_fun(t_scanner *scan, int status)
{
	if (scan->redirect == REDIRECT_1 || scan->redirect == REDIRECT_2)
		dup2(scan->fd, 1);
	while (status < 0)
	{	
		if (scan->count_rev == 0)
			status = execve(scan->format_cmd[scan->i], \
					scan->all_words2, scan->env);
		if (scan->format_cmd[scan->i] == NULL && status < 0)
		{
			wait(NULL);
			scan->global_exit = INVALID_CMD;
			break ;
		}
		scan->i++;
	}
}

void	if_redirect_exe(t_scanner *scan)
{
	if (scan->redirect == REDIRECT_1)
	{
		while (scan->i < scan->n_file - 1)
		{
			scan->fd = open(scan->file_re[scan->i], O_CREAT | O_TRUNC, 0755);
			scan->i++ ;
		}
		scan->fd = open(scan->file_re[scan->i], O_RDWR \
			| O_CREAT | O_TRUNC, 0755);
	}
	if (scan->redirect == REDIRECT_2)
	{
		while (scan->i < scan->n_file)
		{
			scan->fd = open(scan->file_re[scan->i], \
				O_RDWR | O_CREAT | O_APPEND, 0755);
			scan->i++;
		}
	}
}

int	check_execve(t_scanner *scan)
{
	int		status;
	pid_t	pid;

	status = -1;
	scan->i = 0;
	scan->global_exit = SUCCESS;
	conversion_command(scan, scan->command);
	if_redirect_exe(scan);
	pid = fork();
	scan->i = 0;
	if (pid == 0)
		execve_fun(scan, status);
	else
		wait(NULL);
	if (scan->redirect == REDIRECT_1 || scan->redirect == REDIRECT_2)
		close(scan->fd);
	return (status);
}
