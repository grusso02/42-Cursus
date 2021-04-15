/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:48:31 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 16:11:11 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
		[(int)(player->pos_x + player->dir_x * player->mov_speed)] == 0)
		set_position(player, player->dir_x * player->mov_speed, 0);
	if (layout->map[(int)(player->pos_y + player->dir_y * player->mov_speed)]
		[(int)(player->pos_x)] == 0)
		set_position(player, 0, player->dir_y * player->mov_speed);
}

void	move_backward(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
		[(int)(player->pos_x - player->dir_x * player->mov_speed)] == 0)
		set_position(player, -(player->dir_x * player->mov_speed), 0);
	if (layout->map[(int)(player->pos_y - player->dir_y * player->mov_speed)]
		[(int)(player->pos_x)] == 0)
		set_position(player, 0, -(player->dir_y * player->mov_speed));
}

void	move_right(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
		[(int)(player->pos_x + player->plan_x * player->mov_speed)] == 0)
		set_position(player, player->plan_x * player->mov_speed, 0);
	if (layout->map[(int)(player->pos_y + player->plan_y * player->mov_speed)]
		[(int)(player->pos_x)] == 0)
		set_position(player, 0, player->plan_y * player->mov_speed);
}

void	move_left(t_layout *layout, t_player *player)
{
	if (layout->map[(int)(player->pos_y)]
		[(int)(player->pos_x - player->plan_x * player->mov_speed)] == 0)
		set_position(player, -(player->plan_x * player->mov_speed), 0);
	if (layout->map[(int)(player->pos_y - player->plan_y * player->mov_speed)]
		[(int)(player->pos_x)] == 0)
		set_position(player, 0, -(player->plan_y * player->mov_speed));
}
