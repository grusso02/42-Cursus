/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:27:54 by grusso            #+#    #+#             */
/*   Updated: 2021/04/16 17:27:55 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_colors(int r, int g, int b)
{
	if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
		return (0);
	return (1);
}

int	get_color_handle(char **rgb, t_game *game)
{
	int	r;
	int	g;
	int	b;
	int	color;

	color = 0;
	if (!rgb[0] || !rgb[1] || !rgb[2])
		exit_failure("Wrong data for the color;\n", game);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (check_colors(r, g, b))
	{
		color = r;
		color = (color << 8) + g;
		color = (color << 8) + b;
	}
	else
		exit_failure("Wrong data for the color;\n", game);
	return (color);
}
