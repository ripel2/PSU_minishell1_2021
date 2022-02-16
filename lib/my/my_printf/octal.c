/*
** EPITECH PROJECT, 2021
** octal.c
** File description:
** Function to print octal numbers
*/

#include "my_printf.h"
#include "../my.h"
#include <stdlib.h>

int signed_octal_special_cases(char *res, int *nbr)
{
    if (*nbr == 0) {
        res[0] = '0';
        res[1] = '\0';
        return (1);
    }
    if (*nbr == -2147483648) {
        free(res);
        res = my_strcpy_m("-20000000000");
        return (1);
    }
    return (0);
}

char *signed_octal(int nbr)
{
    char *res = malloc(sizeof(char) * 17);
    int c = 0;
    int is_neg = nbr < 0 ? 1 : 0;
    int rem;

    if (signed_octal_special_cases(res, &nbr) == 1)
        return (res);
    (is_neg == 1) ? nbr = nbr * -1 : 0;
    while (nbr != 0) {
        rem = nbr % 8;
        res[c++] = rem + '0';
        nbr = nbr / 8;
    }
    if (is_neg)
        res[c++] = '-';
    res[c] = '\0';
    my_revstr(res);
    return res;
}

char *octal(unsigned long long nbr)
{
    return (my_putunbr_base(nbr, "01234567"));
}

void octal_append(char *res, char *octal, int *c, char ch)
{
    res[(*c)++] = '\\';
    (ch < 8) ? res[(*c)++] = '0' : 0;
    (ch < 32) ? res[(*c)++] = '0' : 0;
    for (int i = 0; i < my_strlen(octal); i++)
        res[i + *c] = octal[i];
    *c += my_strlen(octal);
    free(octal);
}

char *show_str_octal(char *str)
{
    int size = 1;
    int c = 0;
    char *res;

    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] < ' ' || str[n] > 127)
            size += 4;
        else
            size++;
    }
    res = malloc(sizeof(char) * size);
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] < ' ' || str[n] > 127)
            octal_append(res, signed_octal(str[n]), &c, str[n]);
        else
            res[c++] = str[n];
    }
    return (res);
}
