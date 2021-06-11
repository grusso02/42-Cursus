/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:38:24 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 15:40:43 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_all_str(t_scanner *scan, char *cmd)
{
	if (scan->trigger == 0)
	{
		scan->lst = ft_lstnew(ft_strdup(cmd));
		scan->trigger = 1;
	}
	else
	{
		scan->lst_tmp = ft_lstnew(ft_strdup(cmd));
		ft_lstadd_back(&(scan->lst), scan->lst_tmp);
	}
}

void	get_all_str2(t_scanner *scan, char *cmd)
{
	if (scan->trigger3 == 0)
	{
		scan->lst2 = ft_lstnew(ft_strdup(cmd));
		scan->trigger3 = 1;
	}
	else
	{
		scan->lst_tmp3 = ft_lstnew(ft_strdup(cmd));
		ft_lstadd_front(&(scan->lst2), scan->lst_tmp3);
	}
}
