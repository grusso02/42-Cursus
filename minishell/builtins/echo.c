/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:21:07 by gabriele          #+#    #+#             */
/*   Updated: 2021/05/31 15:36:00 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_quotes2(t_scanner *scan, char *str, char tmp)
{
	int	t;
	int	i;

	t = 0;
	i = 0;
	if (scan->arg[0] == '"' || scan->arg[0] == 39)
	{
		i++;
		tmp = scan->arg[0];
	}
	if (scan->arg[ft_strlen(scan->arg) - 1] == tmp)
		scan->arg[ft_strlen(scan->arg) - 1] = 0;
	while (scan->arg[i])
	{
		if (scan->arg[i] != tmp)
			str[t++] = scan->arg[i];
		i++;
	}
	str[t] = 0;
	free(scan->arg);
	scan->arg = ft_strdup(str);
	free(str);
}

void	check_quotes(t_scanner *scan)
{
	int		i;
	int		t;
	char	tmp;
	char	*str;

	str = NULL;
	tmp = 0;
	i = 0;
	t = 0;
	if (scan->arg[0] == '"' || scan->arg[0] == 39)
	{
		i++;
		tmp = scan->arg[0];
	}
	if (scan->arg[ft_strlen(scan->arg) - 1] == tmp)
		scan->arg[ft_strlen(scan->arg) - 1] = 0;
	while (scan->arg[i])
	{
		if (scan->arg[i] != tmp)
			t++;
		i++;
	}
	free(str);
	str = (char *)malloc(sizeof(char) * t + 1);
	check_quotes2(scan, str, tmp);
}

void	ft_echo1(t_scanner *scan)
{
	int	t;

	t = 0;
	scan->arg += 1;
	while (scan->env[t])
	{
		if (!ft_strncmp(scan->env[t], scan->arg, ft_strlen(scan->arg)))
		{
			if (scan->env[t][ft_strlen(scan->arg)] == '=')
			{
				scan->env[t] += (ft_strlen(scan->arg) + 1);
				ft_putstr_fd(scan->env[t], 1);
				write(1, "\n", 1);
				scan->env[t] -= (ft_strlen(scan->arg) + 1);
			}
		}
		t++;
	}
	scan->arg -= 1;
}

void	ft_echo2(char *str, int flag_n)
{
	if (!ft_strncmp(str, "-n", 2) && ft_isspace(str[2]))
	{
		flag_n = 1;
		str = str + 2;
		while (str && ft_isspace(*str))
			str++;
	}
	write(1, str, ft_strlen(str));
	if (!flag_n)
		write(1, "\n", 1);
}

int	ft_echo(t_scanner *scan)
{
	char	*str;
	int		flag_n;
	int		t;

	t = 0;
	flag_n = 0;
	check_quotes(scan);
	if (!strcmp(scan->arg, "$?"))
		printf("%d\n", scan->ret);
	str = ft_strdup(scan->arg);
	while (scan->arg[t])
		t++;
	if (scan->arg[0] == '$' && scan->arg[1] != '(' && scan->arg[t - 1] != ')')
		ft_echo1(scan);
	else
		ft_echo2(str, flag_n);
	free(str);
	return (scan->ret = 0);
}
