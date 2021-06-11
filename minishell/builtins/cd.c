/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:24:52 by gabriele          #+#    #+#             */
/*   Updated: 2021/05/31 16:01:43 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd(t_scanner *scan)
{
	int		cd_ret;
	char	*tmp;
	char	pwd[100];

	tmp = NULL;
	if (!ft_strcmp(scan->arg, ""))
		scan->arg = ft_strdup(getenv("HOME"));
	check_quotes(scan);
	cd_ret = chdir(scan->arg);
	if (cd_ret)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(scan->arg, 2);
		ft_putchar_fd('\n', 2);
		return (scan->ret = 1);
	}
	getcwd(pwd, 100);
	scan->path = ft_strdup(pwd);
	reload_env(scan);
	return (scan->ret = 0);
}
