/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:09:28 by grusso            #+#    #+#             */
/*   Updated: 2021/02/07 18:37:25 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processing_pointer(va_list ap, t_data *data)
{
	char	*str;
	void	*s;
	int		count;

	count = 0;
	s = va_arg(ap, void *);
	data->l_format = 'x';
	str = ft_itoa_base((unsigned long)s, 16, data);
	if (*str == '0' && data->point && !data->precision)
		str = "";
	str = ft_strjoin("0x", str);
	if (!data->minus && data->width)
		count += ft_printf("%*s", data->width, str);
	else if (data->minus && data->width)
		count += ft_printf("%-*s", data->width, str);
	else
		count += ft_printf("%-*s", data->width, str);
	free(str);
	return (count);
}
