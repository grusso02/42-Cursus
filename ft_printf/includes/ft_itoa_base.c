/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:35:52 by grusso            #+#    #+#             */
/*   Updated: 2021/02/06 19:27:54 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long	ft_pow(unsigned long nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

unsigned long	check_value(unsigned long value, int base, int neg)
{
	if (value < 0)
	{
		neg = (base == 10) ? 1 : 0;
		value *= -1;
	}
	return (value);
}

char			*ft_itoa_base(unsigned long value, int base, t_data *data)
{
	unsigned long	i;
	char			*nbr;
	int				neg;

	i = 1;
	neg = 0;
	value = check_value(value, base, neg);
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		if (data->l_format == 'X')
			nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		else if (data->l_format == 'x')
			nbr[i + neg] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
