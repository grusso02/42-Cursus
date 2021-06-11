/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:44:35 by grusso            #+#    #+#             */
/*   Updated: 2021/01/17 18:30:51 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *el;

	if (!(el = (t_list *)malloc(sizeof(t_list))))
		return (0);
	el->content = content;
	el->next = NULL;
	return (el);
}
