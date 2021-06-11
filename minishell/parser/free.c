/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:03:14 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 16:12:07 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_pipe(t_scanner *scan)
{
	int	i;

	i = 0;
	while (scan->all_words3[i])
		free(scan->all_words3[i++]);
	free(scan->all_words3);
	i = 0;
	while (scan->piped[i])
		free(scan->piped[i++]);
	free(scan->piped);
	i = 0;
	while (scan->piped2[i])
		free(scan->piped2[i++]);
	free(scan->piped2);
	i = 0;
	while (scan->format_cmd[i])
		free(scan->format_cmd[i++]);
	free(scan->format_cmd);
}

void	ft_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "$ ", 2);
	}
	if (sig == SIGQUIT)
	{
		sig++;
		if (sig == 1)
		{
			write(1, "Quit: 3    \n", 15);
			exit(1);
		}
	}
}

void	free_scanner(t_scanner *scan)
{
	int	j;

	j = 0;
	if (scan->command)
		free(scan->command);
	if (scan->arg)
		free(scan->arg);
	if (scan->all_words2)
	{
		j = 0;
		while (scan->all_words2[j] != NULL)
			free(scan->all_words2[j++]);
		free(scan->all_words2);
	}
	if (scan->file_re)
	{
		j = 0;
		while (scan->file_re[j] != NULL)
			free(scan->file_re[j++]);
		free(scan->file_re);
		scan->file_re = NULL;
	}
	free_scanner2(scan);
}

void	free_scanner2(t_scanner *scan)
{
	int	j;

	j = 0;
	if (scan->all_words)
	{
		j = 0;
		while (scan->all_words[j] != NULL)
			free(scan->all_words[j++]);
		free(scan->all_words);
	}
	j = 0;
	if (scan->arg_exec)
	{
		while (scan->arg_exec[j])
			free(scan->arg_exec[j++]);
		free(scan->arg_exec);
	}
}

void	free_format_cmd(t_scanner *scan)
{
	int	j;

	j = 0;
	while (scan->format_cmd[j])
		free(scan->format_cmd[j++]);
	free(scan->format_cmd);
}
