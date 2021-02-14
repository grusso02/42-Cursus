/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:29:26 by grusso            #+#    #+#             */
/*   Updated: 2021/02/10 16:55:09 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_list(t_data *data)
{
	data->minus = 0;
	data->zero = 0;
	data->width = 0;
	data->point = 0;
	data->precision = 0;
	data->star = 0;
	data->sign = 0;
	data->sign_precision = 0;
	data->format = 0;
	data->l_format = 0;
}

int		ft_printf(const char *format, ...)
{
	t_data	data;
	va_list ap;
	int		count;

	ft_reset_list(&data);
	va_start(ap, format);
	count = ft_check_str(format, ap, &data);
	va_end(ap);
	return (count);
}
