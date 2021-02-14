/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:34:43 by grusso            #+#    #+#             */
/*   Updated: 2021/02/06 17:46:49 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	sign;
	size_t	size;

	sign = n;
	size = n > 0 ? 0 : 1;
	sign = sign > 0 ? sign : -sign;
	while (n)
	{
		n /= 10;
		size++;
	}
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	*(str + size--) = '\0';
	while (sign > 0)
	{
		*(str + size--) = sign % 10 + '0';
		sign /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}
