/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:36:56 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 16:13:43 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_game *game)
{
	key_manager(game);
	mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
	raycasting(game, game->player, game->window, game->ray);
	return (0);
}
