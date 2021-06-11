/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:18:35 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 17:22:18 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_format(t_scanner *scan, char *cmd, char *path, int len)
{
	scan->count++;
	scan->z = scan->i;
	scan->j = 0;
	while (path[scan->z] && path[scan->z++] != ':' )
		scan->j++;
	scan->format_cmd[scan->count] = malloc(sizeof(char *) * scan->j + 1 + len);
	scan->j = 0;
	while (path[scan->i] && path[scan->i] != ':')
		scan->format_cmd[scan->count][scan->j++] = path[scan->i++];
	scan->z = 0;
	scan->format_cmd[scan->count][scan->j++] = '/';
	while (cmd[scan->z])
		scan->format_cmd[scan->count][scan->j++] = cmd[scan->z++];
	scan->format_cmd[scan->count][scan->j] = '\0';
	if (path[scan->i] == ':')
		scan->i++;
}

char	*get_mem_str(t_scanner *scan, char *cmd, char *str, char *path)
{
	while (path[scan->i])
	{
		if (path[scan->i] == ':')
			scan->count++;
		scan->i++;
	}
	scan->i = 0;
	while (cmd[scan->i])
	{
		if (cmd[scan->i] == '/')
			scan->z++;
		scan->i++;
	}
	if (scan->z > 0)
	{
		scan->z = 0;
		while (cmd[scan->i] != '/')
			scan->i--;
		scan->i++;
		while (cmd[scan->i])
			str[scan->z++] = cmd[scan->i++];
		str[scan->z] = '\0';
		cmd = str;
	}
	return (cmd);
}

void	conversion_command(t_scanner *scan, char *cmd)
{	
	char	*path;
	int		len;
	char	*str;

	path = getenv("PATH");
	len = ft_strlen(cmd);
	scan->i = 0;
	scan->j = 0;
	scan->z = 0;
	scan->count = 0;
	str = (char *) malloc(sizeof(char *));
	cmd = get_mem_str(scan, cmd, str, path);
	scan->z = 0;
	scan->i = 0;
	scan->count += 1;
	scan->format_cmd = (char **)malloc(sizeof(char *) * scan->count + 1);
	scan->format_cmd[scan->count] = NULL;
	scan->count = -1;
	while (path[scan->i])
		get_format(scan, cmd, path, len);
	scan->i = 0;
	free(str);
}
