/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:38:55 by grusso            #+#    #+#             */
/*   Updated: 2021/02/10 16:38:56 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_int(t_data *data, char *str, int a)
{
	int l;
	int count;

	count = 0;
	l = data->width;
	if (a == 1)
	{
		while (((l--) - ft_strlen(str)))
			count += ft_putchar(' ');
	}
	else
	{
		while (((l--) - ft_strlen(str)))
			count += ft_putchar('0');
	}
	return (count);
}

int		check_zero(t_data *data, char *str)
{
	int count;

	count = 0;
	if (data->zero == 1)
	{
		if (data->sign && (data->l_format == 'd' || data->l_format == 'i'))
		{
			count += ft_putchar('-');
			count += ft_putchar_int(data, str, 0);
			count += ft_putstr(str + 1);
		}
		else
		{
			count += ft_putchar_int(data, str, 0);
			count += ft_putstr(str);
		}
	}
	else
	{
		count += ft_putchar_int(data, str, 1);
		count += ft_putstr(str);
	}
	return (count);
}

int		ft_putchar_int_p(t_data *data, char *str, int a)
{
	int l;
	int count;

	count = 0;
	l = (data->sign && data->l_format != 'u' &&
	data->l_format != 'x' && data->l_format != 'X') ? -1 : 0;
	if (a == 1)
	{
		if (data->width > data->precision && data->precision < ft_strlen(str))
			l += data->width - ft_strlen(str);
		else if (data->width > data->precision)
			l += data->width - data->precision;
		else if (data->width > data->precision && !data->precision)
			l += data->width - data->precision - 1;
		while (l-- > 0)
			count += ft_putchar(' ');
	}
	else if (a == 0 && data->precision > ft_strlen(str))
	{
		l = data->precision;
		while (((l--) - ft_strlen(str)))
			count += ft_putchar('0');
	}
	return (count);
}

int		unciafazzchiu(t_data *data, char *str, unsigned int n)
{
	int count;

	count = 0;
	if (data->l_format == 'd' || data->l_format == 'i')
		str = ft_itoa((int)n);
	else if (data->l_format == 'u')
		str = ft_itoa_unsigned((unsigned int)n);
	else if (data->l_format == 'x' || data->l_format == 'X')
		str = ft_itoa_base((unsigned long)n, 16, data);
	count = print_data(str, data);
	free(str);
	return (count);
}
