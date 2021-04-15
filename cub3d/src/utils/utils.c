/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:18:25 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 16:18:26 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdirection(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

int	ft_isrow(char *row)
{
	int	i;

	i = 0;
	if (row[0] == '\0')
		return (0);
	while (row[i])
	{
		if (!ft_isdigit(row[i]) && !ft_isdirection(row[i]) && row[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isempty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& line[i] != '\t' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}
