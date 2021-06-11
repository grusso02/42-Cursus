/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:25:23 by gabriele          #+#    #+#             */
/*   Updated: 2021/05/31 15:37:34 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pass_env(t_scanner *scan, char *envp[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			scan->env[i][j] = envp[i][j];
			j++;
		}
		scan->env[i][j] = 0;
		i++;
	}
	envp[i] = 0;
}

void	take_env(t_scanner *scan, char *envp[])
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
		i++;
	scan->env = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
			j++;
		scan->env[i] = (char *)malloc(sizeof(char) * j + 1);
		i++;
	}
	pass_env(scan, envp);
}

void	reload_env(t_scanner *scan)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	tmp = "PWD=";
	while (scan->env[i] && ft_strncmp(scan->env[i], "PWD=", 4))
		i++;
	free(scan->env[i]);
	j = 0;
	if (!ft_strcmp(scan->path, ""))
		scan->path = ft_strdup("/");
	while (scan->path[j])
		j++;
	scan->env[i] = (char *)malloc(sizeof(char) * j + 5);
	j = 4;
	ft_strlcpy(scan->env[i], tmp, 5);
	while (*scan->path)
		scan->env[i][j++] = *scan->path++;
	scan->env[i][j] = 0;
}

int	ft_env(t_scanner *scan)
{
	int	i;

	i = 0;
	while (scan->env[i])
		printf("%s\n", scan->env[i++]);
	return (scan->ret = 0);
}
