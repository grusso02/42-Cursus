/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:53:36 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 16:57:31 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	alloc_redirect(t_scanner *scan)
{
	scan->file_re = (char **)malloc(sizeof(char *) * scan->count + 1);
	scan->file_re[scan->count] = NULL;
	scan->n_file = scan->count;
	scan->count = 0;
}

int	make_redirect(t_scanner *scan, int len)
{
	scan->count = 0;
	scan->redirect = REDIRECT_1;
	while (scan->all_words[scan->i] && scan->all_words[scan->i][0] != '>')
		scan->i++;
	scan->all_words2 = (char **)malloc(sizeof(char *) * scan->i + 1);
	scan->all_words2[scan->i] = NULL;
	scan->i = 0;
	while (scan->all_words[scan->i][0] != '>')
	{
		scan->all_words2[scan->i] = ft_strdup(scan->all_words[scan->i]);
		scan->i++;
	}
	len = scan->i + 1;
	while (scan->all_words[scan->i])
	{
		if (scan->all_words[scan->i][0] != '>')
			scan->count++;
		else
		{
			if (scan->all_words[scan->i][1] == '>')
				scan->redirect = REDIRECT_2;
		}
		scan->i++;
	}
	return (len);
}

void	make_allwords2(t_scanner *scan)
{
	while (scan->all_words[scan->i])
		scan->i++;
	scan->all_words2 = (char **)malloc(sizeof(char *) * scan->i + 1);
	scan->all_words2[scan->i] = NULL;
	scan->i = 0;
	while (scan->all_words[scan->i])
	{
		scan->j = 0;
		scan->all_words2[scan->i] = malloc(sizeof(char) \
			* ft_strlen(scan->all_words[scan->i]) + 1);
		while (scan->all_words[scan->i][scan->j])
		{
			scan->all_words2[scan->i][scan->j] = \
				scan->all_words[scan->i][scan->j];
			scan->j++;
		}
		scan->all_words2[scan->i][scan->j] = '\0';
		scan->i++;
	}
}

void	init_redirect(t_scanner *scan)
{
	scan->i = 0;
	scan->j = 0;
	scan->count = 0;
	scan->n_file = 0;
	scan->redirect = NOT_REDIRECT;
}

void	check_redirect(t_scanner *scan)
{
	int	len;

	init_redirect(scan);
	while (scan->all_words[scan->i])
	{
		if (scan->all_words[scan->i][0] == '>')
			scan->count++;
		if (scan->all_words[scan->i])
			scan->i++;
	}
	scan->i = 0;
	if (scan->count == 0)
		make_allwords2(scan);
	else
	{
		len = make_redirect(scan, 0);
		alloc_redirect(scan);
		while (scan->all_words[len])
		{
			if (scan->all_words[len][0] != '>')
				scan->file_re[scan->count++] = ft_strdup(scan->all_words[len]);
			len++;
		}
	}	
}
