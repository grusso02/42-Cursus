/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:17:17 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 18:06:16 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_wall(t_game *game, t_ray *ray)
{
	int		text_x;
	t_image	*texture;

	texture = game->we_texture;
	if (ray->side == 1)
		texture = game->ea_texture;
	else if (ray->side == 2)
		texture = game->no_texture;
	else if (ray->side == 3)
		texture = game->so_texture;
	text_x = (int)(ray->wall_x * (double)texture->width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		text_x = texture->width - text_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		text_x = texture->width - text_x - 1;
	ray->text_x = text_x;
	set_texture_on_image(game, texture, ray);
}

void	draw_col(t_game *game, t_window *window, t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + window->height / 2;
	ray->draw_end = ray->line_height / 2 + window->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= window->height)
		ray->draw_end = window->height - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->wall_x = game->player->pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player->pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	set_wall(game, ray);
	set_color_on_image(game, ray);
}
