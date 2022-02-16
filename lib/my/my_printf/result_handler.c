/*
** EPITECH PROJECT, 2021
** result_handler.c
** File description:
** Function to handle the result
*/

#include "my_printf.h"
#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *number_sign_flag(flag_t *flag, char *result)
{
    char *pre;

    if (is_in(flag->spec, "xX") &&
    !(my_strlen(result) == 1 && result[0] == '0')) {
        pre = flag->spec == 'x' ? "0x" : "0X";
        result = my_strcat_m(pre, result);
        return (result);
    }
    if (flag->spec == 'o' &&
    !(my_strlen(result) == 1 && result[0] == '0')) {
        result = my_strcat_m("0", result);
        return (result);
    }
    if (flag->spec == 'b' &&
    !(my_strlen(result) == 1 && result[0] == '0')) {
        result = my_strcat_m("0b", result);
        return (result);
    }
    return (result);
}

char *number_sign(flag_t *flag, char *result)
{
    if (my_strlen(result) > 0 && result[0] != '-'
    && is_in(flag->spec, "diuobxX")) {
        result = my_strcat_m("+", result);
        return (result);
    }
    return (result);
}

char *cut_result(flag_t *flag, char *result)
{
    char *res = malloc(sizeof(char) * (flag->max_width + 1));
    int len = flag->max_width;

    for (int c = 0; c < len; c++)
        res[c] = result[c];
    return (res);
}

void put_result(flag_t *flag, char *result, pftarget_t *target)
{
    if (is_in('#', flag->flags))
        result = number_sign_flag(flag, result);
    if (is_in('+', flag->flags))
        result = number_sign(flag, result);
    if (is_in(' ', flag->flags))
        result = my_strcat_m(" ", result);
    if (is_in('-', flag->flags))
        result = left_justify(flag, result, ' ');
    if (is_in('0', flag->flags) && flag->width >= 0)
        result = left_fill(flag, result, '0');
    else if (flag->width >= 0)
        result = left_fill(flag, result, ' ');
    if (flag->max_width >= 0 && my_strlen(result) > flag->max_width)
        result = cut_result(flag, result);
    write(target->fd, result, my_strlen(result));
    target->chars_written += my_strlen(result);
}
