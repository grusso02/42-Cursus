/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:41:12 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 15:46:29 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../includes/minishell.h"

void	get_arg(t_scanner *scan, char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++ ;
	scan->arg = malloc(sizeof(char *) * (ft_strlen(str) - i + 1));
	while (str[i] != '\0')
	{
		scan->arg[j] = str[i];
		i++;
		j++;
	}
	scan->arg[j] = '\0';
}

void	get_exec_arg(t_scanner *scan)
{	
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (scan->all_words[i])
		i++ ;
	scan->arg_exec = (char **)malloc(sizeof(char *) * i);
	scan->arg_exec[i - 1] = NULL;
	i = 1;
	while (scan->all_words[i])
		scan->arg_exec[j++] = ft_strdup(scan->all_words[i++]);
}
