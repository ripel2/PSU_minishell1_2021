/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Prints a given number, any int, to the current stream.
*/

#include "my.h"

void put_max_neg(void)
{
    char str[] = "-2147483648";

    for (int c = 0; str[c] != '\0'; c++)
        my_putchar(str[c]);
}

void my_put_nbr(int nb)
{
    int temp;

    if (nb == -2147483648) {
        put_max_neg();
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        temp = nb / 10;
        nb = nb - 10 * temp;
        my_put_nbr(temp);
    }
    my_putchar('0' + nb);
}
