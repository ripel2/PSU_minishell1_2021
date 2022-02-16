/*
** EPITECH PROJECT, 2021
** parsing.c
** File description:
** Function to parse the flag given
*/

#include "my_printf.h"
#include "../my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int is_length(char const *ch)
{
    if (my_strncmp(ch, "hh", 2) == 0)
        return (2);
    if (my_strncmp(ch, "ll", 2) == 0)
        return (2);
    if (my_strncmp(ch, "h", 1) == 0)
        return (1);
    if (my_strncmp(ch, "l", 1) == 0)
        return (1);
    if (my_strncmp(ch, "z", 1) == 0)
        return (1);
    return (0);
}

int get_length(char const *ch)
{
    if (my_strncmp(ch, "hh", 2) == 0)
        return (TYPE_INT);
    if (my_strncmp(ch, "ll", 2) == 0)
        return (TYPE_LONG_LONG);
    if (my_strncmp(ch, "h", 1) == 0)
        return (TYPE_INT);
    if (my_strncmp(ch, "l", 1) == 0)
        return (TYPE_LONG);
    if (my_strncmp(ch, "z", 1) == 0)
        return (TYPE_LONG_LONG);
    return (0);
}

void get_width(char const *format, int *c, int *width, int *max_width)
{
    if (my_is_nbr(format[*c])) {
        *width = my_getnbr(format + *c);
        while (my_is_nbr(format[*c]))
            (*c)++;
    }
    if (format[*c] == '.' && my_is_nbr(format[*c + 1])) {
        (*c)++;
        *max_width = my_getnbr(format + *c);
        while (my_is_nbr(format[*c]))
            (*c)++;
    }
}

void adjust_type(flag_t *flag)
{
    if (is_in(flag->spec, "uoxX") && flag->type == TYPE_LONG)
        flag->type = TYPE_ULONG;
    if (is_in(flag->spec, "uoxX") && flag->type == TYPE_LONG_LONG)
        flag->type = TYPE_ULONG_LONG;
}

flag_t *parse_flag(char const *format, int *c)
{
    flag_t *flag = malloc(sizeof(flag_t));

    flag->spec = 0;
    flag->type = -1;
    flag->max_width = -1;
    flag->width = -1;
    flag->flags = "";
    flag->pos = *c;
    while (is_in(format[*c], " -+#0")) {
        flag->flags = my_str_addchar(flag->flags, format[*c]);
        (*c)++;
    }
    get_width(format, c, &flag->width, &flag->max_width);
    if (is_length(format + *c)) {
        flag->type = get_length(format + *c);
        (*c) += is_length(format + *c);
    }
    flag->spec = is_in(format[*c], "diuoxXcsSpb%") ? format[*c] : 0;
    adjust_type(flag);
    return (flag);
}
