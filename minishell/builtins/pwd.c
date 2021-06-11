/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:24:21 by gabriele          #+#    #+#             */
/*   Updated: 2021/05/31 15:12:46 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(t_scanner *scan)
{
	char	pwd[100];

	if (getcwd(pwd, 100))
		ft_putendl_fd(pwd, 1);
	return (scan->ret = 0);
}
