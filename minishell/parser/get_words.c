/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:14:57 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 16:21:09 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_words(t_scanner *scan, char *str)
{
	scan->i++;
	scan->z = scan->i;
	scan->count = 0;
	while (str[scan->i] && str[scan->i] == '"')
	{
		scan->z++;
		scan->i++;
	}
	if (str[scan->i] != '"' && str[scan->i] != '\0')
	{
		while (str[scan->z] != '"')
		{
			scan->count++;
			scan->z++;
		}
		malloc_str(scan);
		while (str[scan->i] && str[scan->i] != '"')
		{
			scan->all_words[scan->x][scan->z] = str[scan->i];
			scan->i++;
			scan->z++;
		}
		scan->all_words[scan->x][scan->z] = '\0';
	}
	scan->i++;
}

void	get_words2(t_scanner *scan, char *str)
{
	scan->i++;
	scan->z = scan->i;
	scan->count = 0;
	while (str[scan->i] && str[scan->i] == 39)
	{
		scan->z++;
		scan->i++;
	}
	if (str[scan->i] != 39 && str[scan->i] != '\0')
	{
		while (str[scan->z] != 39)
		{
			scan->count++;
			scan->z++;
		}
		malloc_str(scan);
		while (str[scan->i] && str[scan->i] != 39)
		{
			scan->all_words[scan->x][scan->z] = str[scan->i];
			scan->i++;
			scan->z++;
		}
		scan->all_words[scan->x][scan->z] = '\0';
	}
	scan->i++;
}

void	get_words3(t_scanner *scan, char *str)
{
	scan->count = 0;
	scan->z = scan->i;
	scan->x++;
	while (str[scan->z] && str[scan->z] != ' ' && str[scan->z] != '\t' \
		&& str[scan->z] != 39 && str[scan->z] != '"')
	{
		scan->count++;
		scan->z++;
	}	
	scan->z = 0;
	scan->all_words[scan->x] = malloc(sizeof(char *) * scan->count + 1);
	while (str[scan->i] && str[scan->i] != ' ' && str[scan->i] != '\t' && \
		str[scan->i] != 39 && str[scan->i] != '"')
		scan->all_words[scan->x][scan->z++] = str[scan->i++];
	scan->all_words[scan->x][scan->z] = '\0';
}

void	allocate_word(t_scanner *scan, char *str)
{
	while (str[scan->i])
	{
		while (str[scan->i] == ' ')
			scan->i++;
		if (str[scan->i] == '\0')
			break ;
		if (str[scan->i] == '"' || str[scan->i] == 39)
		{
			analyze_quot(scan, str);
			analyze_quot2(scan, str);
		}
		else
			normal_count(scan, str);
	}
	set_words(scan);
}

void	all_words(t_scanner *scan, char *str)
{
	scan->i = 0;
	scan->x = 0;
	scan->count = 0;
	scan->valid_arg = 0;
	allocate_word(scan, str);
	while (str[scan->i])
	{
		scan->count = 0;
		while (str[scan->i] == ' ' || str[scan->i] == '\t')
			scan->i++ ;
		if (str[scan->i] == '\0')
			break ;
		if (str[scan->i] == '"' || str[scan->i] == 39)
		{
			if (str[scan->i] == '"')
				get_words(scan, str);
			else
				get_words2(scan, str);
		}
		else
			get_words3(scan, str);
	}
}
