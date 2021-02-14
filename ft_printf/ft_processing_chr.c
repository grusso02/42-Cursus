/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:32:15 by grusso            #+#    #+#             */
/*   Updated: 2021/02/06 16:15:11 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putspace(t_data *data)
{
	int a;
	int count;

	count = 0;
	a = data->width;
	while ((a - 1) != 0)
	{
		ft_putchar(' ');
		a--;
		count++;
	}
	return (count);
}

int		ft_putzero(t_data *data)
{
	int a;
	int count;

	count = 0;
	a = data->width;
	while ((a - 1) != 0)
	{
		ft_putchar('0');
		a--;
		count++;
	}
	return (count);
}

int		ft_percent(t_data *data)
{
	int		count;
	char	c;

	c = '%';
	count = 0;
	if (data->minus == 1 && data->width > 0)
	{
		ft_putchar(c);
		count += ft_putspace(data);
	}
	else if (data->minus == 0 && data->width > 0 && data->zero)
	{
		count += ft_putzero(data);
		ft_putchar(c);
	}
	else if (data->minus == 0 && data->width > 0 && !data->zero)
	{
		count += ft_putspace(data);
		ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (count);
}

int		ft_processing_chr(va_list ap, t_data *data)
{
	char	c;
	int		count;

	count = 1;
	if (data->l_format == '%')
		count += ft_percent(data);
	else
	{
		c = va_arg(ap, int);
		if (data->minus == 1 && data->width > 0)
		{
			ft_putchar(c);
			count += ft_putspace(data);
		}
		else if (data->minus == 0 && data->width > 0)
		{
			count += ft_putspace(data);
			ft_putchar(c);
		}
		else
			ft_putchar(c);
	}
	return (count);
}
