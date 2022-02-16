/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Counts and returns the numbers of character found in
** a given string.
*/

#include "my.h"

int my_strlen(char const *str)
{
    int pos = 0;
    int counter = 0;

    while (*(str + pos) != '\0') {
        counter++;
        pos += 1;
    }
    return (counter);
}
