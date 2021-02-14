/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:18:12 by grusso            #+#    #+#             */
/*   Updated: 2021/01/19 19:16:15 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len(const char *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			i++;
			count = 1;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*st;
	size_t	i;
	size_t	j;

	if (!s || !(ret = (char **)malloc((len(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			st = (char *)s;
			while (*s && *s != c)
				s++;
			j = s - st + 1;
			if (!(ret[i] = (char *)malloc(j)))
				return (0);
			ft_strlcpy(ret[i++], st, j);
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
