/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Returns a given number from a string.
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int pos = 0;
    int result = 0;
    int sign = 1;

    while (*(str + pos) == '-' || *(str + pos) == '+') {
        *(str + pos) == '-' ? sign *= -1 : 0;
        pos++;
    }
    while (*(str + pos) != '\0' && *(str + pos) >= '0'
    && *(str + pos) <= '9') {
        if (result == 214748364 && *(str + pos) > '7' && sign == 1)
            return (0);
        if (result == 214748364 && *(str + pos) > '8' && sign == -1)
            return (0);
        result *= 10;
        result += *(str + pos) - 48;
        pos++;
    }
    return (sign * result);
}
