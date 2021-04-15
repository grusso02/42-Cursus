/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:15:54 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 18:33:19 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_data(char *line, t_game *game)
{
	char	*trim;

	trim = ft_strtrim(line, " ");
	if (!ft_strncmp(trim, "R", 1))
		get_resolution(trim, &(game->window->width),
						&(game->window->height));
	else if (!ft_strncmp(trim, "NO", 2))
		get_texture_path(trim, game->no_texture);
	else if (!ft_strncmp(trim, "SO", 2))
		get_texture_path(trim, game->so_texture);
	else if (!ft_strncmp(trim, "WE", 2))
		get_texture_path(trim, game->we_texture);
	else if (!ft_strncmp(trim, "EA", 2))
		get_texture_path(trim, game->ea_texture);
	else if (!ft_strncmp(trim, "S", 1))
		get_texture_path(trim, game->sp_texture);
	else if (!ft_strncmp(trim, "C", 1))
		get_color(trim, &(game->c_color), game);
	else if (!ft_strncmp(trim, "F", 1))
		get_color(trim, &(game->f_color), game);
	free(trim);
}

static void	get_cub_data(char *line, t_game *game)
{
	if (game->map_started == 1)
	{
		if (game->map_stopped == 1 && !ft_isempty(line))
			exit_failure("The map has a wrong format;\n", game);
		else
		{
			if (ft_isempty(line))
				game->map_stopped = 1;
			else if (ft_isrow(line))
				get_map(line, game);
			else if (game->map_started == 1)
				exit_failure("The map has a wrong format;\n", game);
		}
	}
	else
	{
		if (ft_isrow(line))
		{
			game->map_started = 1;
			get_map(line, game);
		}
		else
			get_data(line, game);
	}
}

void	read_map(char *map_path, t_game *game)
{
	int			fd;
	char		*line;

	fd = open(map_path, O_RDONLY);
	if ((fd) < 0)
		exit_failure("The file doesn't exist;\n", game);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			get_cub_data(line, game);
			free(line);
		}
		get_cub_data(line, game);
		free(line);
		check_cub_data(game);
		get_layout(game);
		check_layout(game, game->layout, game->player);
	}
	close (fd);
}
