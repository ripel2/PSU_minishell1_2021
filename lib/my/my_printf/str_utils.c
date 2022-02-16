/*
** EPITECH PROJECT, 2021
** str_utils.c
** File description:
** Useful functions for strings
*/

#include "my_printf.h"
#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

char *my_strcat_m(char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);
    char *res = malloc(sizeof(char) * (str1_len + str2_len + 1));

    for (int c = 0; str1[c] != '\0'; c++)
        res[c] = str1[c];
    for (int d = 0; str2[d] != '\0'; d++)
        res[str1_len + d] = str2[d];
    res[str1_len + str2_len] = '\0';
    return (res);
}

char *my_str_addchar(char *str1, char c)
{
    int str1_len = my_strlen(str1);
    char *res = malloc(sizeof(char) * (str1_len + 2));

    for (int d = 0; str1[d] != '\0'; d++)
        res[d] = str1[d];
    res[str1_len] = c;
    res[str1_len + 1] = '\0';
    return (res);
}

char *my_strcpy_m(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    int c = 0;

    for (c = 0; str[c] != '\0'; c++)
        res[c] = str[c];
    res[c] = '\0';
    return (res);
}

char *left_fill(flag_t *flag, char *result, char fill)
{
    int res_len = my_strlen(result);
    char *zfill;
    int c = 0;

    if (res_len < flag->width) {
        zfill = malloc(sizeof(char) * (flag->width - res_len + 1));
        for (c = 0; c < flag->width - res_len; c++)
            zfill[c] = fill;
        zfill[c] = '\0';
        result = my_strcat_m(zfill, result);
        free(zfill);
    }
    return (result);
}

char *left_justify(flag_t *flag, char *result, char fill)
{
    int res_len = my_strlen(result);
    char *zfill;
    int c = 0;

    if (res_len < flag->width) {
        zfill = malloc(sizeof(char) * (flag->width - res_len + 1));
        for (c = 0; c < flag->width - res_len; c++)
            zfill[c] = fill;
        zfill[c] = '\0';
        result = my_strcat_m(result, zfill);
        free(zfill);
    }
    return (result);
}
