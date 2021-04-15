/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_differential_analyser.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:36:29 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 17:46:27 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_wall_dist(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == -1)
			ray->side = 0;
		else
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == -1)
			ray->side = 2;
		else
			ray->side = 3;
	}
}

void	dda(t_game *game, t_layout *layout, t_ray *ray)
{
	while (ray->hit != 1)
	{
		get_wall_dist(ray);
		if (layout->map[ray->map_y][ray->map_x] >= 1
			&& layout->map[ray->map_y][ray->map_x] != 2)
			ray->hit = 1;
		else if (layout->map[ray->map_y][ray->map_x] == 2)
			is_sprite(game, ray);
	}
}
