/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:39:05 by grusso            #+#    #+#             */
/*   Updated: 2021/05/31 15:57:55 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_prompt1(void)
{
	write(1, "$ ", 2);
}

void	init_scan(t_scanner *scan)
{
	scan->tot_len = 0;
	scan->len_str = 0;
	scan->count = 0;
	scan->trigger = 0;
	scan->trigger2 = 0;
	scan->trigger3 = 0;
	scan->glob_len = 0;
	scan->glob_len2 = 0;
	scan->glob_len3 = 0;
	scan->first = 2;
	scan->path = NULL;
	scan->signal = 0;
	scan->ret = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	exit_shell(char *cmd, t_scanner *scan, int err)
{
	if (err == INVALID_CMD)
	{
		write (1, "Error: command not valid\n", 26);
		if (scan->global_exit == INVALID_CMD)
			exit(0);
	}
	if (err == MALLOC_ERROR)
	{
		printf("MALLOC ERROR\n");
		free(cmd);
	}
	if (err == EXIT)
	{
		free_all(scan);
		free_scanner(scan);
		exit(0);
	}
	if (err == QUOTES)
		printf("ERROR: quotes\n");
	if (err == REDIRECT_ERR)
		printf("ERROR: redirect\n");
	scan->ret = 1;
}

void	free_all(t_scanner *scan)
{
	int	count;

	count = 0;
	while (scan->split_str[count])
		free(scan->split_str[count++]);
	free(scan->split_str);
}
