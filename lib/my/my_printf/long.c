/*
** EPITECH PROJECT, 2021
** long.c
** File description:
** Functions for longs
*/

#include "../my.h"
#include "my_printf.h"
#include <stdlib.h>

int my_put_long_special_cases(char *res, long *nbr)
{
    if (*nbr == 0) {
        res[0] = '0';
        res[1] = '\0';
        return (1);
    }
    if (*nbr == -9223372036854775807 - 1) {
        free(res);
        res = my_strcpy_m("-9223372036854775808");
        return (1);
    }
    return (0);
}

char *my_put_long(long nbr)
{
    char *res = malloc(sizeof(char) * 21);
    int c = 0;
    int is_neg = nbr < 0 ? 1 : 0;
    long rem;

    if (my_put_long_special_cases(res, &nbr) == 1)
        return (res);
    (is_neg == 1) ? nbr = nbr * -1 : 0;
    while (nbr != 0) {
        rem = nbr % 10;
        res[c++] = rem + '0';
        nbr = nbr / 10;
    }
    if (is_neg)
        res[c++] = '-';
    res[c] = '\0';
    my_revstr(res);
    return (res);
}

char *unsigned_long(unsigned long nb)
{
    return (my_putunbr_base(nb, "0123456789"));
}
