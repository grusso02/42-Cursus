/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:31:15 by grusso            #+#    #+#             */
/*   Updated: 2021/02/07 15:59:10 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_data_processing(va_list ap, t_data *data)
{
	int count;

	count = 0;
	if (data->l_format == 'c' || data->l_format == '%')
		count = ft_processing_chr(ap, data);
	else if (data->l_format == 's')
		count = ft_processing_str(ap, data);
	else if (data->l_format == 'd' || data->l_format == 'i' ||
			data->l_format == 'u' || data->l_format == 'x' ||
			data->l_format == 'X')
		count = ft_processing_int(ap, data);
	else if (data->l_format == 'p')
		count = ft_processing_pointer(ap, data);
	return (count);
}
