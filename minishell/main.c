/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:32:55 by grusso            #+#    #+#             */
/*   Updated: 2021/05/30 17:13:00 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	check_if_cmd(t_scanner *scan)
{
	int	res;
	int	i;

	i = 0;
	while (scan->split_str[i])
	{
		get_command(scan, scan->split_str[i]);
		if (scan->command == NULL)
			break ;
		get_arg(scan, scan->split_str[i]);
		all_words(scan, scan->split_str[i]);
		get_exec_arg(scan);
		check_redirect(scan);
		check_pipe(scan->split_str[i], scan);
		check_reverse_red(scan, scan->split_str[i]);
		if (scan->count_pipe < 1 && scan->count_rev < 1)
		{
			res = cmp_command(scan);
			parse_cmd(res, scan, scan->split_str[i]);
		}
		free_scanner(scan);
		i++;
	}
}

char	*set_cmd(char *cmd)
{
	int	j;

	j = 0;
	while (cmd[j])
		j++;
	j--;
	while (cmd[j] == ' ' || cmd[j] == '\t')
		j--;
	cmd[j + 1] = '\0';
	return (cmd);
}

void	scanner(char *cmd, t_scanner *scan)
{
	cmd = set_cmd(cmd);
	get_all_str(scan, cmd);
	get_all_str2(scan, cmd);
	split_string(scan);
	check_if_cmd(scan);
}

int	main(int ac, char **av, char *envp[])
{
	char		*cmd;
	t_scanner	scan;

	(void)ac;
	(void)av;
	init_scan(&scan);
	take_env(&scan, envp);
	welcome();
	while (1)
	{
		signal(SIGINT, ft_handler);
		signal(SIGQUIT, ft_handler);
		print_prompt1();
		rawmode(&scan);
		cmd = ft_strdup(scan.buf);
		if (ft_strcmp(cmd, "") != 0)
		{
			scanner(cmd, &scan);
			free_all(&scan);
		}
		free(cmd);
	}
	return (0);
}
