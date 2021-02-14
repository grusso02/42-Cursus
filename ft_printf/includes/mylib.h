/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:35:23 by grusso            #+#    #+#             */
/*   Updated: 2021/02/06 18:08:08 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include "../ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);

#endif
