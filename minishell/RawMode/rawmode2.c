/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:03:31 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 15:10:54 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	if_up4(int replay, t_scanner *scan)
{
	if (scan->glob_len == 1)
	{
		scan->glob_len = scan->glob_len2 + 1;
		replay = 1;
	}
	return (replay);
}

int	if_up3(t_scanner *scan)
{
	t_list	*tmp2;
	t_list	*tmp;

	tmp2 = scan->lst;
	tmp = ft_lstlast_len(tmp2, scan->glob_len);
	while (tmp->content[scan->i])
	{
		scan->buf[scan->i] = tmp->content[scan->i];
		write(1, &scan->buf[scan->i], 1);
		scan->i++ ;
	}
	return (scan->i);
}

void	if_up2(t_scanner *scan)
{
	while (scan->i >= 1)
	{
		scan->buf[scan->i--] = '\0';
		write(1, "\b", 1);
		write(1, " ", 1);
		write(1, "\b", 1);
	}
}

void	if_up(t_scanner *scan)
{
	t_list	*tmp2;
	t_list	*tmp;

	if (scan->c == ARROW_UP)
	{
		if (scan->down_attivo == 1)
		{
			scan->down_attivo = 0;
			scan->glob_len--;
		}
		if (scan->glob_len >= 0)
		{
			if_up2(scan);
			scan->i = 0;
			tmp2 = scan->lst;
			tmp = ft_lstlast_len(tmp2, scan->glob_len);
			scan->i = if_up3(scan);
			scan->replay = if_up4(scan->i, scan);
			scan->glob_len--;
		}
		scan->up_attivo = 1;
	}
}

void	if_down2(t_scanner *scan, t_list *tmp, t_list *tmp2)
{
	if (scan->replay == 1)
	{
		scan->replay = 0;
		scan->glob_len = 1;
	}
	scan->glob_len++;
	while (scan->i >= 1)
	{
		scan->buf[scan->i--] = '\0';
		write(1, "\b", 1);
		write(1, " ", 1);
		write(1, "\b", 1);
	}
	scan->i = 0;
	tmp2 = scan->lst;
	tmp = ft_lstlast_len(tmp2, scan->glob_len);
	while (tmp->content[scan->i])
	{
		scan->buf[scan->i] = tmp->content[scan->i];
		write(1, &scan->buf[scan->i], 1);
		scan->i++;
	}
}
