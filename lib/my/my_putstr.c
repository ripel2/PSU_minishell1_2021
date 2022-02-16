/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Displays one-by-one the characters of a string by
** giving the function the address of the string
** first character.
*/

#include "my.h"

void my_putstr(char const *str)
{
    int pos = 0;

    while (*(str + pos) != '\0') {
        my_putchar(*(str + pos));
        pos += 1;
    }
}
