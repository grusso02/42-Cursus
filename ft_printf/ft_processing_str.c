/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:02:48 by grusso            #+#    #+#             */
/*   Updated: 2021/02/06 16:36:30 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_precision(t_data *data, char *str)
{
	int len;
	int count;

	count = 0;
	if (data->precision >= ft_strlen(str))
		len = ft_strlen(str);
	else
		len = data->precision;
	if (data->minus == 1 && data->width > 0)
	{
		count += ft_putstr_str(str, len);
		count += ft_putspace_str(data, len);
	}
	else if (data->minus == 0 && data->width > 0)
	{
		count += ft_putspace_str(data, len);
		count += ft_putstr_str(str, len);
	}
	else
		count += ft_putstr_str(str, len);
	return (count);
}

int		ft_print(t_data *data, char *str)
{
	int count;

	count = 0;
	if (data->minus == 1 && data->width >= ft_strlen(str))
	{
		count += ft_putstr(str);
		count += ft_putspace_str2(data, str);
	}
	else if (data->minus == 0 && data->width >= ft_strlen(str))
	{
		count += ft_putspace_str2(data, str);
		count += ft_putstr(str);
	}
	else
		count += ft_putstr(str);
	return (count);
}

int		ft_processing_str(va_list ap, t_data *data)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (!data->precision && data->sign_precision)
		data->point = 0;
	if (!data->point)
		count += ft_print(data, str);
	else
		count += ft_print_precision(data, str);
	return (count);
}
