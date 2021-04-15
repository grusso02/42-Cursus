/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:15:05 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 17:52:36 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(char *map_path, char *option, t_game *game)
{
	char	**path;
	int		path_len;

	path_len = 0;
	if (map_path)
	{
		path = ft_split(map_path, '.');
		while (path[path_len])
			path_len++;
		if (ft_strncmp(path[path_len - 1], "cub", 4))
		{
			exit_failure("Wrong extension for the map;\n", game);
		}
		free_split(path);
	}
	if (option)
	{
		if (ft_strncmp(option, "--save", 7))
		{
			exit_failure("Wrong option;\n", game);
		}
	}
	return (EXIT_SUCCESS);
}
