/*
** EPITECH PROJECT, 2021
** putchar_pf.c
** File description:
** Putchar for the printf
*/

#include "my_printf.h"
#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

char *putchar_pf(char c)
{
    char *res = malloc(sizeof(char) * 2);

    res[0] = c;
    res[1] = '\0';
    return (res);
}
