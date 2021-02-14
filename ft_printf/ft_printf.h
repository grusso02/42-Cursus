/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:30:02 by grusso            #+#    #+#             */
/*   Updated: 2021/02/10 16:39:24 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "includes/mylib.h"

# include <stdarg.h>
# include <stdio.h>

typedef struct	s_data
{
	int		minus;
	int		zero;
	int		width;
	int		point;
	int		precision;
	int		star;
	int		sign;
	int		sign_precision;
	int		format;
	char	l_format;
}				t_data;

char			*ft_itoa_base(unsigned long value, int base, t_data *data);
char			*ft_strjoin(char const *s1, char const *s2);

int				ft_printf(const char *format, ...);
void			ft_reset_list(t_data *data);

int				ft_check_str(const char *str, va_list ap, t_data *data);
void			ft_check_flag(const char *str, t_data *data);
void			ft_check_width(const char *str, va_list ap, t_data *data);
void			ft_check_precision(const char *str, va_list ap, t_data *data);
void			ft_check_format(const char *str, t_data *data);

void			ft_check_flag(const char *str, t_data *data);
void			ft_check_width(const char *str, va_list ap, t_data *data);
void			ft_check_precision(const char *str, va_list ap, t_data *data);
void			ft_check_format(const char *str, t_data *data);

int				ft_data_processing(va_list ap, t_data *data);
int				ft_processing_chr(va_list ap, t_data *data);

int				ft_processing_str(va_list ap, t_data *data);
int				ft_putspace_str(t_data *data, int len);
int				ft_putspace_str2(t_data *data, char *str);
int				ft_putstr_str(char *str, int len);

int				ft_processing_int(va_list ap, t_data *data);
int				print_data(char *str, t_data *data);
int				unciafazzchiu(t_data *data, char *str, unsigned int n);
int				ft_putchar_int(t_data *data, char *str, int a);
int				check_zero(t_data *data, char *str);
int				ft_putchar_int_p(t_data *data, char *str, int a);

int				ft_processing_pointer(va_list ap, t_data *data);

#endif
