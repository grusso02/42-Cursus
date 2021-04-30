/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:40:06 by grusso            #+#    #+#             */
/*   Updated: 2021/04/30 17:19:58 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
    char a[50] = "Ciao";
    char b[50];
    char c[50] = "Si";

    //ft_strlen
    printf("FT_STRLEN:\n%zu\n", ft_strlen(a));
    printf("STRLEN:\n%lu\n\n", strlen(a));

    //ft_strcpy
    printf("FT_STRCPY:\n%s\n", ft_strcpy(b, a));
    printf("STRCPY:\n%s\n\n", strcpy(b, a));

    //ft_strcmp
    printf("FT_STRCMP:\n%d\n", ft_strcmp(a, c));
    printf("FT_STRCMP:\n%d\n\n", strcmp(a, c));

    //ft_write
    printf("FT_WRITE:\n");
    ft_write(1, "Ciao\n", 5);
    printf("WRITE:\n");
    write(1, "Ciao\n\n", 6);

    //ft_read
    char    buffer[3000];
    int     fd = open("text.txt", O_RDONLY);
    ft_read(fd, buffer, 3000);
    printf("FT_READ:\n%s\n\n", buffer);

    //ft_strdup
    printf("FT_STRDUP:\n%s\n", ft_strdup(a));
    printf("STRDUP:\n%s\n\n", strdup(a));
}