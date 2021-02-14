/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:27:12 by grusso            #+#    #+#             */
/*   Updated: 2021/02/07 18:37:20 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*cat;

	if (!s1 || !s2 || !(cat = malloc(sizeof(char) *
					(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		cat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		cat[j++] = s2[i++];
	cat[j] = 0;
	free((char *)s2);
	return (cat);
}
