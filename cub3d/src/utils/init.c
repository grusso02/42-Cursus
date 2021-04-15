/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:18:09 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 18:15:43 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_keys	*keys_struct_init(void)
{
	t_keys	*keys;

	keys = (t_keys *)malloc(sizeof(t_keys));
	if (!(keys))
		return (NULL);
	keys->key_a = 0;
	keys->key_s = 0;
	keys->key_d = 0;
	keys->key_w = 0;
	keys->key_esc = 0;
	keys->left_arr = 0;
	keys->right_arr = 0;
	return (keys);
}

t_player	*player_struct_init(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!(player))
		return (NULL);
	player->pos_x = 0.5;
	player->pos_y = 0.5;
	player->dir_x = 0.;
	player->dir_y = 0.;
	player->mov_speed = 0.17;
	player->rot_speed = 0.12;
	player->plan_x = 0.;
	player->plan_y = 0.;
	player->dir = '0';
	return (player);
}

t_layout	*layout_struct_init(void)
{
	t_layout	*layout;

	layout = (t_layout *)malloc(sizeof(t_layout));
	if (!(layout))
		return (NULL);
	layout->map = NULL;
	layout->tmp_map = NULL;
	layout->nb_col = 0;
	layout->nb_row = 0;
	return (layout);
}

t_window	*window_struct_init(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (!(window))
		return (NULL);
	window->width = 0;
	window->height = 0;
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	return (window);
}

t_game	*game_struct_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!(game))
		return (NULL);
	game->map_started = 0;
	game->map_stopped = 0;
	game->save = 0;
	game->c_color = 0;
	game->f_color = 0;
	game->sprites_head = NULL;
	game->no_texture = image_struct_init();
	if (!(game->no_texture)
		|| !(game->so_texture = image_struct_init())
		|| !(game->we_texture = image_struct_init())
		|| !(game->ea_texture = image_struct_init())
		|| !(game->sp_texture = image_struct_init())
		|| !(game->image = image_struct_init())
		|| !(game->player = player_struct_init())
		|| !(game->layout = layout_struct_init())
		|| !(game->window = window_struct_init())
		|| !(game->keys = keys_struct_init()))
		return (NULL);
	return (game);
}
