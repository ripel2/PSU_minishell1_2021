/*
** EPITECH PROJECT, 2021
** my_lowercase
** File description:
** Function that puts every letter of every word in lowercase
*/

#include "my.h"

char char_to_lowercase(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return (letter + 32);
    return (letter);
}

char *my_strlowcase(char *str)
{
    int strlen = my_strlen(str);
    int c;

    for (c = 0; c < strlen; c++)
        str[c] = char_to_lowercase(str[c]);
    return (str);
}
