/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:11:16 by grusso            #+#    #+#             */
/*   Updated: 2021/02/07 17:59:23 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char *str, t_data *data)
{
	if (data->precision == 0 && data->width == 0)
	{
		if (data->minus && data->zero)
			data->zero = 0;
		else if (*str == '-')
			data->minus = 1;
		else if (*str == '0')
			data->zero = 1;
	}
}

void	ft_check_width(const char *str, va_list ap, t_data *data)
{
	if (data->point == 0)
	{
		if (*str == '*')
		{
			data->width = va_arg(ap, int);
			if (data->width < 0)
			{
				data->width *= -1;
				data->minus = 1;
			}
		}
		else
		{
			if ((*str) >= '0' && (*str) <= '9')
				data->width = (data->width * 10) + (*str - '0');
		}
	}
}

void	ft_check_precision(const char *str, va_list ap, t_data *data)
{
	if (*str == '.')
	{
		data->point = 1;
		str++;
		if (!((*str) >= '0' && (*str) <= '9') && *str != '*')
			data->precision = 0;
		else if (*str == '*')
		{
			data->precision = va_arg(ap, int);
			if (data->precision < 0)
			{
				data->sign_precision = 1;
				data->precision = 0;
			}
		}
		else
		{
			while ((*str) >= '0' && (*str) <= '9')
			{
				data->precision = (data->precision * 10) + (*str - '0');
				str++;
			}
		}
	}
}

void	ft_check_format(const char *str, t_data *data)
{
	if ((*str) == 'd' || (*str) == 'i' || (*str) == 'c' || (*str) == 's' ||
			(*str) == 'p' || (*str) == 'u' || (*str) == 'x' ||
			(*str) == 'X' || (*str) == '%')
	{
		data->format = 1;
		data->l_format = *str;
	}
	if (data->l_format == 'p' && data->sign_precision)
		data->precision = 1;
}
