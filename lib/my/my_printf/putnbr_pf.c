/*
** EPITECH PROJECT, 2021
** putstr_pf.c
** File description:
** Putnbr for the printf
*/

#include "my_printf.h"
#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int putnbr_pf_special_cases(char *res, int *nbr)
{
    if (*nbr == 0) {
        res[0] = '0';
        res[1] = '\0';
        return (1);
    }
    if (*nbr == -2147483648) {
        free(res);
        res = my_strcpy_m("-2147483648");
        return (1);
    }
    return (0);
}

char *putnbr_pf(int nbr)
{
    char *res = malloc(sizeof(char) * 13);
    int c = 0;
    int is_neg = nbr < 0 ? 1 : 0;
    int rem;

    if (putnbr_pf_special_cases(res, &nbr) == 1)
        return (res);
    if (is_neg == 1)
        nbr = nbr * -1;
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
