/*
** EPITECH PROJECT, 2021
** print_numbers.c
** File description:
** Functions to print numbers
*/

#include "my_printf.h"
#include "../my.h"
#include <stdlib.h>

char *my_putunbr_base(unsigned long long nbr, char const *base)
{
    int strlen = my_strlen(base);
    char *res = malloc(sizeof(char) * 65);
    int i = 0;

    for (int c = 0; c < 65; c++)
        res[c] = 0;
    if (nbr == 0)
        res[0] = base[0];
    while (nbr > 0) {
        res[i] = base[nbr % strlen];
        nbr = nbr / strlen;
        i++;
    }
    my_revstr(res);
    return (res);
}

char *unsigned_int(unsigned int nb)
{
    return (my_putunbr_base((unsigned long long)nb, "0123456789"));
}

char *unsigned_hex(unsigned long long n)
{
    return (my_putunbr_base(n, "0123456789abcdef"));
}

char *unsigned_hex_uppercase(unsigned long long n)
{
    return (my_putunbr_base(n, "0123456789ABCDEF"));
}

char *unsigned_bin(unsigned long long n)
{
    return (my_putunbr_base(n, "01"));
}
