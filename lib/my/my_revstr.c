/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Function that reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int end = my_strlen(str) - 1;
    int start = 0;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}
