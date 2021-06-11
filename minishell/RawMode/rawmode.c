/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:59:28 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 15:02:55 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	if_no_print(t_scanner *scan)
{
	if (scan->c == 4)
		exit(0);
}

void	if_ten(t_scanner *scan)
{
	write(1, "\n", 1);
	write(1, "\r", 1);
	scan->glob_len++;
	scan->glob_len2++;
	scan->glob_len = scan->glob_len2;
}

void	if_noprint2(t_scanner *scan)
{
	if (scan->c == 4)
		exit(0);
	if (scan->c == 127)
	{
		if (scan->i >= 1)
		{
			scan->buf[scan->i--] = '\0';
			write(1, "\b", 1);
			write(1, " ", 1);
			write(1, "\b", 1);
		}
	}
	else if (scan->c != ARROW_UP && scan->c != ARROW_DOWN)
	{
		scan->buf[scan->i++] = scan->c;
		write(1, &scan->buf[scan->i - 1], 1);
	}
}

void	set_zero_iter(t_scanner *scan)
{
	scan->i = 0;
	scan->up_attivo = 0;
	scan->down_attivo = 0;
	scan->replay = 0;
}

void	rawmode(t_scanner *scan)
{
	set_zero_iter(scan);
	enableRawMode();
	while (1)
	{
		scan->c = editorReadKey();
		if_up(scan);
		if_down(scan);
		if (scan->c == 10)
		{
			if_ten(scan);
			break ;
		}
		if_no_print(scan);
		if_noprint2(scan);
	}
	scan->buf[scan->i] = '\0';
	if (ft_strlen(scan->buf) < 1 && scan->c == 10)
	{
		scan->glob_len2--;
		scan->glob_len--;
	}
}
