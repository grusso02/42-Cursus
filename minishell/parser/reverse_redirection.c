/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:58:00 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 17:00:38 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_cmd_reverse(t_scanner *scan, char *s, int i)
{
	int	count;

	count = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
		count++;
		i++;
	}
	scan->command_reverse = malloc(sizeof(char *) * count + 1);
	scan->command_reverse[count] = '\0';
	while (s[--i])
		scan->command_reverse[--count] = s[i];
}

void	free_rev(t_scanner *scan)
{
	int	i;

	i = 0;
	while (scan->red_rev_all[i])
		free(scan->red_rev_all[i++]);
	free(scan->red_rev_all);
	i = 0;
	while (scan->red_rev_split[i])
		free(scan->red_rev_split[i++]);
	free(scan->red_rev_split);
	free(scan->command_reverse);
	i = 0;
}

void	check_reverse_red(t_scanner *scan, char *str)
{
	int	i;

	i = 0;
	scan->count_rev = 0;
	while (str[i])
	{
		if (str[i++] == '<')
			scan->count_rev++;
	}
	if (scan->count_rev > 0)
	{
		i = 0;
		scan->red_rev_all = ft_split(str, '<');
		get_cmd_reverse(scan, scan->red_rev_all[0], 0);
		conversion_command(scan, scan->command_reverse);
		while (scan->red_rev_all[i])
		{
			scan->red_rev_split = ft_split(scan->red_rev_all[i], ' ');
			exec_redrev(scan, scan->red_rev_split, -1, 0);
			i++;
		}
		free_rev(scan);
	}
}
