/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Concatenates two strings with only n characters from the source string.
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int destlen = my_strlen(dest);
    int c;

    for (c = 0; src[c] != '\0' && c < nb; c++)
        dest[destlen + c] = src[c];
    dest[destlen + c] = '\0';
    return (dest);
}
