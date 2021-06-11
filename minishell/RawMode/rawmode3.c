/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:11:33 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/30 14:35:47 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

struct termios	g_raw;

void	disableRawMode(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_orig_termios);
}

void	enableRawMode(void)
{
	tcgetattr(STDIN_FILENO, &g_orig_termios);
	atexit(disableRawMode);
	g_raw = g_orig_termios;
	g_raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_raw);
}

char	editorReadKey(void)
{
	int		nread;
	char	c;
	char	seq[3];

	nread = read(STDIN_FILENO, &c, 1);
	while (nread != 1)
		if (nread == -1 && errno != EAGAIN)
			die("read");
	if (c == '\x1b')
	{
		if (read(STDIN_FILENO, &seq[0], 1) != 1)
			return ('\x1b');
		if (read(STDIN_FILENO, &seq[1], 1) != 1)
			return ('\x1b');
		if (seq[0] == '[')
		{
			if (seq[1] == 'A')
				return (ARROW_UP);
			else if (seq[1] == 'B')
				return (ARROW_DOWN);
		}
	}
	return (c);
}

t_list	*ft_lstlast_len(t_list *lst, int len)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (i < len - 1)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}

void	if_down(t_scanner *scan)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (scan->c == ARROW_DOWN)
	{
		if (scan->up_attivo == 1)
		{
			scan->up_attivo = 0;
			scan->glob_len++;
		}
		if (scan->glob_len < scan->glob_len2 || scan->replay == 1)
		{
			if_down2(scan, tmp, tmp2);
		}
		scan->down_attivo = 1;
	}
}
