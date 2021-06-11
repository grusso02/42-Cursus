/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_redirection2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:05:10 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/30 15:23:52 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_redirection2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:05:09 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 17:05:09 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_redirection2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:00:59 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/05/29 17:04:44 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_redrevstr(t_scanner *scan, int z, char **str)
{
	int		i;
	int		k;
	char	**nstr;

	i = 1;
	k = 1;
	while (str[z])
		z++;
	if (z > 1)
	{
		k = 0;
		z -= 1;
	}
	nstr = (char **)malloc(sizeof(char *) * z + 2);
	nstr[0] = ft_strdup(scan->command_reverse);
	nstr[z + 1] = NULL;
	while (i <= z)
	{
		nstr[i] = ft_strdup(str[i - k]);
		i++;
	}
	nstr[i + 1] = NULL;
	return (nstr);
}

void	execution_redrev(t_scanner *scan, int z, int status, char **nstr)
{
	while (status < 0)
	{
		status = execve(scan->format_cmd[z], nstr, scan->env);
		if (scan->format_cmd[z] == NULL && status < 0)
		{
			wait(NULL);
			scan->global_exit = INVALID_CMD;
			exit_shell(scan->command, scan, INVALID_CMD);
		}
		z++;
	}
}

void	exec_redrev(t_scanner *scan, char **str, int status, int z)
{
	int		fd;
	char	**nstr;
	pid_t	pid;

	fd = dup(STDIN_FILENO);
	scan->global_exit = SUCCESS;
	nstr = get_redrevstr(scan, z, str);
	pid = fork();
	if (pid == 0)
	{
		status = -1;
		conversion_command(scan, scan->command_reverse);
		dup2(1, fd);
		dup2(0, fd);
		z = 0;
		execution_redrev(scan, z, status, nstr);
	}
	else
		wait(NULL);
	close(fd);
	close(fd);
}
