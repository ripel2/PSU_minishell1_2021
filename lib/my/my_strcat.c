/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Concatenates two strings.
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int destlen = my_strlen(dest);
    int c;

    for (c = 0; src[c] != '\0'; c++)
        dest[destlen + c] = src[c];
    dest[destlen + c] = '\0';
    return (dest);
}
