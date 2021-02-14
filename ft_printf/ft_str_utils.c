/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:32:55 by grusso            #+#    #+#             */
/*   Updated: 2021/02/06 17:19:35 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putspace_str(t_data *data, int len)
{
	int a;
	int count;

	count = 0;
	a = data->width;
	if (a > len)
	{
		while ((a - len) > 0)
		{
			count += ft_putchar(' ');
			a--;
		}
	}
	return (count);
}

int		ft_putspace_str2(t_data *data, char *str)
{
	int a;
	int count;

	count = 0;
	a = data->width;
	while ((a - ft_strlen(str)) > 0)
	{
		count += ft_putchar(' ');
		a--;
	}
	return (count);
}

int		ft_putstr_str(char *str, int len)
{
	int count;

	count = 0;
	while (*str && len--)
		count += ft_putchar(*str++);
	return (count);
}
