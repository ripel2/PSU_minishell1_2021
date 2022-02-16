/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** Copy of the strstr function
*/

#include <stdio.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int pos = 0;
    int to_find_len = my_strlen(to_find);

    while (*(str + pos) != '\0') {
        if (my_strncmp(str + pos, to_find, to_find_len) == 0)
            return (str + pos);
        pos++;
    }
    return NULL;
}
