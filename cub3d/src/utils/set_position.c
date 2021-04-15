/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:18:20 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 18:22:52 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spaghetti2(t_player *player)
{
	if (player->dir == 'W')
		player->dir_x = -1.;
	else
		player->dir_x = 1.;
	player->dir_y = 0.;
	player->plan_x = 0.;
	if (player->dir == 'W')
		player->plan_y = -0.66;
	else
		player->plan_y = 0.66;
}

void	set_position(t_player *player, float pos_x, float pos_y)
{
	player->pos_x += pos_x;
	player->pos_y += pos_y;
}

void	init_player(t_player *player)
{
	if (player->dir == 'N' || player->dir == 'S')
	{
		player->dir_x = 0.;
		if (player->dir == 'N')
			player->dir_y = -1.;
		else
			player->dir_y = 1.;
		if (player->dir == 'N')
			player->plan_x = 0.66;
		else
			player->plan_x = -0.66;
		player->plan_y = 0.;
	}
	else if (player->dir == 'W' || player->dir == 'E')
		spaghetti2(player);
}
