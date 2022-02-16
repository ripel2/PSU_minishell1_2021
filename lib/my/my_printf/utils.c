/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** Useful functions
*/

#include "my_printf.h"
#include "../my.h"

int is_in(char ch, char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == ch)
            return (1);
    return (0);
}
