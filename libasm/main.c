/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:40:06 by grusso            #+#    #+#             */
/*   Updated: 2021/04/30 16:53:55 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int     check_ft_strlen()
{
    char a[50];
    char b[50];
    printf("      FT_STRLEN() TESTER\n\n");
    printf("inserisci una parola\n");
    scanf("%s",a);
    printf("inserisci una parola\n");
    scanf("%s",b);
    printf("strlen di %s = %zu\n",a,ft_strlen(a));
    printf("strlen di %s = %zu\n\n\n",b,ft_strlen(b));
    printf("test ft_strlen: SUCCESS\n\n");
    return (0);
}

int     check_ft_strcpy()
{
    printf("    FT_STRCPY() TESTER\n\n");
    char    a[50];
    char    b[50];
 /*    printf("inserisci la destinazione a\n");
    scanf("%s",a); */
    printf("inserisci la sorgente b\n");
    scanf("%s",b);
    ft_strcpy(a,b);

    printf("la stringa copiata in a è %s\n",a);
    printf("la sorgente é %s\n\n",b);
    printf("test : SUCCESS\n\n");
    return (0);

}


int     check_ft_strcmp()
{
    char a[50];
    char b[50];
    int cmp;
    printf("     FT_STRCMP() TESTER\n\n");
    printf("inserisci la stringa n1°\n");
    scanf("%s",a);
    printf("inserisci la stringa n2°\n");
    scanf("%s",b);
    cmp = ft_strcmp(a,b);
    printf("ft_strcmp = %d\n\n\n",cmp);
    printf("test ft_strcmp : SUCCESS\n\n");
    return (0);
}

void     check_ft_write()
{
    char    a[50];
    int len;
    printf("    FT_WRITE() TESTER\n\n");
    printf("inserisci cio che vuoi stampare\nusando\
    la funzione write:\n");
    scanf("%s",a);
    len = ft_strlen(a);
    printf("\n   la funzione ft_write stampa:\n");
    ft_write(1, &a,len);
    printf("\ntest ft_write: SUCCESS\n\n");
}


void   check_ft_read(char **argv)
{
	char	buffer[3000];
    char    test_file[50];
    printf("inserisci il file di testo\n");
    printf("suggerimento : usa -->text.txt<--\n");
    printf("o puoi crearne uno tu\n");
    scanf("%s",test_file);
    argv[1] = test_file;
	int		r1;
	int		fd;
	fd = open(argv[1], O_RDONLY);
	r1 = ft_read(fd, buffer,3000);
	buffer[r1] = 0;
	printf("%s\n", buffer);
    printf("test ft_read: SUCCESS\n\n");
} 

int     check_ft_strdup()
{
    char *a;
    char b[50];
    char c[50];
    printf("    FT_STRDUP TESTER\n");
    printf("copia la stringa n2° in n1°\n");
    printf("inserisci la stringa n2°\n");
    scanf("%s",b);
    printf("stringa n2° = %s\n",b);
    printf("premi -copy- per copiare n°2 in n°1\n");
    scanf("%s",c);
    a = ft_strdup(b);
    printf("stringa n1° = %s\n",a);
    printf("test ft_strdup : SUCCESS\n");
    return (0);
}

int main(int argc, char **argv)
{
    argc = 1;
    if (check_ft_strlen() != 0) printf("errore ft_strlen\n");
    if (check_ft_strcpy() != 0) printf("errore ft_strcpy\n");
    if (check_ft_strcmp() != 0) printf("errore ft_strcmp\n");
    check_ft_write();
    check_ft_read(argv);
    check_ft_strdup();

    printf("\n\n----------------->\n\n");
    printf("    LIBASM TESTER EFFETTUATO CON SUCCESSO\n");
    printf("\n\n----------------->\n\n");  
}