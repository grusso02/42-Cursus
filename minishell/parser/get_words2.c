/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:30:50 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 16:34:07 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	normal_count(t_scanner *scan, char *str)
{
	while (str[scan->i] == ' ' || str[scan->i] == '\t')
		scan->i++ ;
	if (str[scan->i] && str[scan->i] != ' ' && str[scan->i] != '\t' \
		&& str[scan->i] != '"' && str[scan->i] != 39)
	{
		scan->count++ ;
		while (str[scan->i] && str[scan->i] != ' ' && \
			str[scan->i] != '\t' && str[scan->i] != '"' && str[scan->i] != 39)
			scan->i++;
	}
}

void	analyze_quot2(t_scanner *scan, char *str)
{
	if (str[scan->i] == 39)
	{
		scan->i++;
		if (str[scan->i] == 39)
			scan->i++;
		else
		{
			scan->count++;
			while (str[scan->i] && str[scan->i] != 39)
				scan->i++;
			if (str[scan->i] != 39)
			{
				exit_shell(scan->command, scan, QUOTES);
				scan->valid_arg = INVALID_CMD;
			}
			else
				scan->i++;
		}
	}
}

void	analyze_quot(t_scanner *scan, char *str)
{
	if (str[scan->i] == '"')
	{
		scan->i++;
		if (str[scan->i] == '"')
			scan->i++;
		else
		{
			scan->count++;
			while (str[scan->i] && str[scan->i] != '"')
				scan->i++;
			if (str[scan->i] != '"')
			{
				exit_shell(scan->command, scan, QUOTES);
				scan->valid_arg = INVALID_CMD;
			}
			else
				scan->i++;
		}
	}
}

void	set_words(t_scanner *scan)
{
	scan->all_words = (char **)malloc(sizeof(char *) * scan->count + 1);
	scan->all_words[scan->count] = NULL;
	scan->i = 0;
	scan->x = -1 ;
	scan->z = 0;
}

void	malloc_str(t_scanner *scan)
{
	scan->x++;
	scan->all_words[scan->x] = malloc(sizeof(char *) * scan->count + 1);
	scan->z = 0;
}
