/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:20:58 by grusso            #+#    #+#             */
/*   Updated: 2021/02/10 16:56:28 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision_int2(t_data *data, char *str)
{
	int count;

	count = 0;
	if (data->sign && (data->l_format == 'd' || data->l_format == 'i'))
	{
		if (data->width > data->precision)
			count += ft_putchar_int_p(data, str + 1, 1);
		count += ft_putchar('-');
		count += ft_putchar_int_p(data, str + 1, 0);
		count += ft_putstr(str + 1);
	}
	else
	{
		if (data->width > data->precision)
			count += ft_putchar_int_p(data, str, 1);
		count += ft_putchar_int_p(data, str, 0);
		count += ft_putstr(str);
	}
	return (count);
}

int		ft_precision_int0(t_data *data, char *str)
{
	int count;

	count = 0;
	count += ft_putchar('-');
	count += ft_putchar_int_p(data, str + 1, 0);
	count += ft_putstr(str + 1);
	if (data->width > data->precision)
		count += ft_putchar_int_p(data, str, 1);
	return (count);
}

int		ft_precision_int(t_data *data, char *str)
{
	int count;

	count = 0;
	if (data->minus == 1 && data->precision >= 0)
	{
		if (data->sign && (data->l_format == 'd' || data->l_format == 'i'))
			count += ft_precision_int0(data, str);
		else
		{
			count += ft_putchar_int_p(data, str, 0);
			count += ft_putstr(str);
			if (data->width > data->precision)
				count += ft_putchar_int_p(data, str, 1);
		}
	}
	else if (!data->minus && data->precision >= 0)
		count += ft_precision_int2(data, str);
	else
		count += ft_putstr(str);
	return (count);
}

int		print_data(char *str, t_data *data)
{
	int count;

	count = 0;
	if ((data->point && (data->precision > ft_strlen(str))) ||
		(data->point && (data->precision >= ft_strlen(str) && data->sign)) ||
		(data->point && data->zero && data->precision >= 0 &&
		!data->sign_precision))
		count += ft_precision_int(data, str);
	else
	{
		if (data->minus == 1 && data->width >= ft_strlen(str))
		{
			count += ft_putstr(str);
			count += ft_putchar_int(data, str, 1);
		}
		else if (data->minus == 0 && data->width >= ft_strlen(str))
			count += check_zero(data, str);
		else
			count += ft_putstr(str);
	}
	return (count);
}

int		ft_processing_int(va_list ap, t_data *data)
{
	unsigned int		n;
	char				*str;
	int					count;

	count = 0;
	str = NULL;
	n = va_arg(ap, unsigned int);
	if ((int)n < 0)
		data->sign = 1;
	if ((int)n == 0 && data->point && data->sign_precision)
	{
		str = "0";
		count = print_data(str, data);
	}
	else if ((int)n == 0 && data->point && !data->sign_precision)
	{
		str = "";
		count = print_data(str, data);
	}
	else
		count += unciafazzchiu(data, str, n);
	return (count);
}
