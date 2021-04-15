/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:15:46 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 16:15:48 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture(t_game *game, t_image *texture)
{
	if (!(texture->img_ptr =
		mlx_xpm_file_to_image(game->window->mlx_ptr,
		texture->path,
		&texture->width,
		&texture->height)))
		exit_failure("Impossible to load a texture;\n", game);
	texture->img_data =
		mlx_get_data_addr(texture->img_ptr,
		&(texture->bpp),
		&(texture->size_line),
		&(texture->endian));
}

void		get_texture(t_game *game)
{
	set_texture(game, game->no_texture);
	set_texture(game, game->so_texture);
	set_texture(game, game->we_texture);
	set_texture(game, game->ea_texture);
	if (game->sp_texture->path)
		set_texture(game, game->sp_texture);
}
