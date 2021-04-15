/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:59:21 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 16:10:08 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_player *player)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = player->dir_x;
	player->dir_x = cos(-(player->rot_speed)) * player->dir_x -
					sin(-(player->rot_speed)) * player->dir_y;
	player->dir_y = sin(-(player->rot_speed)) * old_dir_x +
					cos(-(player->rot_speed)) * player->dir_y;
	old_plan_x = player->plan_x;
	player->plan_x = cos(-(player->rot_speed)) * player->plan_x -
					sin(-(player->rot_speed)) * player->plan_y;
	player->plan_y = sin(-(player->rot_speed)) * old_plan_x +
					cos(-(player->rot_speed)) * player->plan_y;
}

void	rotate_right(t_player *player)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = player->dir_x;
	player->dir_x = cos(player->rot_speed) * player->dir_x -
					sin(player->rot_speed) * player->dir_y;
	player->dir_y = sin(player->rot_speed) * old_dir_x +
					cos(player->rot_speed) * player->dir_y;
	old_plan_x = player->plan_x;
	player->plan_x = cos(player->rot_speed) * player->plan_x -
					sin(player->rot_speed) * player->plan_y;
	player->plan_y = sin(player->rot_speed) * old_plan_x +
					cos(player->rot_speed) * player->plan_y;
}
