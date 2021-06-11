/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:05:50 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 17:11:15 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	split_string3(t_scanner *scan, int i, int j, int z)
{
	int		count;
	t_list	*tmp2;

	tmp2 = ft_lstlast(scan->lst);
	count = 0;
	while (tmp2->content[i])
	{
		j = 0;
		while (tmp2->content[i] && tmp2->content[i] != ';')
		{
			j++;
			i++;
		}
		scan->split_str[count] = malloc(sizeof(char *) * j);
		scan->split_str[count][j] = '\0';
		z = i - 1;
		j--;
		while (j >= 0)
			scan->split_str[count][j--] = tmp2->content[z--];
		if (tmp2->content[i] == ';')
			i++;
		count++;
	}
}

int	split_string2(t_scanner *scan, int count)
{
	int		i;
	int		j;
	t_list	*tmp;

	j = 0;
	i = 0;
	count = 0;
	tmp = ft_lstlast(scan->lst);
	while (tmp->content[i])
	{
		j = 0;
		while (tmp->content[i] && tmp->content[i] != ';')
			i++;
		if (tmp->content[i] == ';')
			i++;
		count++;
	}
	return (count);
}

void	split_string(t_scanner *scan)
{
	int	count;

	count = 0;
	count = split_string2(scan, count);
	scan->split_str = (char **)malloc(sizeof(char *) * count + 1);
	scan->split_str[count] = NULL;
	count = 0;
	split_string3(scan, 0, 0, 0);
}
