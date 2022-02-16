/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** Function that puts every letter of every word in uppercase
*/

#include "my.h"

char char_to_uppercase(char letter)
{
    if (letter >= 97 && letter <= 122)
        return (letter - 32);
    return (letter);
}

char *my_strupcase(char *str)
{
    int strlen = my_strlen(str);
    int c;

    for (c = 0; c < strlen; c++)
        str[c] = char_to_uppercase(str[c]);
    return (str);
}
