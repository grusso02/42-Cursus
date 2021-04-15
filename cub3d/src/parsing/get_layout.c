/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:15:36 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 18:00:59 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spaghetti(char *line, int *row, int i)
{
	if (ft_isdigit(line[i]))
		row[i] = '0';
	else
		row[i] = 0;
}

static int	*get_row(char *line, t_game *game, int current_row)
{
	int	*row;
	int	i;

	row = (int *)malloc(sizeof(int) * game->layout->nb_col);
	if (!(row))
		return (NULL);
	i = 0;
	while (i < game->layout->nb_col)
	{
		while (line[i])
		{
			if (ft_isdirection(line[i]))
			{
				set_position(game->player, i, current_row);
				row[i] = 0;
			}
			else
				spaghetti(line, row, i);
			i++;
		}
		while (i < game->layout->nb_col)
			row[i++] = 0;
	}
	return (row);
}

void	get_layout(t_game *game)
{
	char		**split_layout;
	t_layout	*layout;
	int			i;

	layout = game->layout;
	split_layout = ft_split(layout->tmp_map, '\n');
	while (split_layout[(int)layout->nb_row])
	{
		if (layout->nb_col < (int)ft_strlen(split_layout[layout->nb_row]))
			layout->nb_col = (int)ft_strlen(split_layout[layout->nb_row]);
		layout->nb_row++;
	}
	layout->map = (int **)malloc(layout->nb_row * sizeof(int *));
	if (!(layout->map))
		return ;
	i = 0;
	while (i < layout->nb_row)
	{
		layout->map[i] = get_row(split_layout[i], game, i);
		i++;
	}
	free_split(split_layout);
}
