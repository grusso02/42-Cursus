/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:17:58 by grusso            #+#    #+#             */
/*   Updated: 2021/04/15 16:17:59 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}

void	free_sprites(t_sprites **head_ref)
{
	t_sprites *current;
	t_sprites *next;

	current = (*head_ref);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	(*head_ref) = NULL;
}
