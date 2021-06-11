/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <dlanzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:10:08 by grusso            #+#    #+#             */
/*   Updated: 2021/05/08 17:03:28 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		p = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = p;
	}
}
