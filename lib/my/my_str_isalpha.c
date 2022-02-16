/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** Function that returns 1 if the string is alphabetic
** characters only else 0
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    while (*str != '\0') {
        if (my_is_letter(*str) == 0)
            return (0);
        str++;
    }
    return (1);
}
