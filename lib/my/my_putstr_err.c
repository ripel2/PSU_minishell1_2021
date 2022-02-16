/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Displays one-by-one the characters of a string by
** giving the function the address of the string
** first character.
*/

#include "my.h"
#include <unistd.h>

void my_putstr_err(char const *str)
{
    int pos = 0;

    while (*(str + pos) != '\0') {
        write(2, (str + pos), 1);
        pos += 1;
    }
}
