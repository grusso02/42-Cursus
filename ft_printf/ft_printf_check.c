/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:31:43 by grusso            #+#    #+#             */
/*   Updated: 2021/02/09 15:25:40 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checki_chan(const char *str, va_list ap, t_data *data)
{
	ft_check_flag(str, data);
	ft_check_width(str, ap, data);
	ft_check_precision(str, ap, data);
	ft_check_format(str, data);
}

int		ft_check_str(const char *str, va_list ap, t_data *data)
{
	int trigger;
	int count;

	count = 0;
	while (*str)
	{
		trigger = 1;
		ft_reset_list(data);
		if (*str == '%')
		{
			str++;
			while (*str && trigger)
			{
				ft_checki_chan(str, ap, data);
				count += ft_data_processing(ap, data);
				trigger = data->l_format ? 0 : 1;
				str++;
			}
		}
		else
			count += ft_putchar(*str++);
	}
	return (count);
}
