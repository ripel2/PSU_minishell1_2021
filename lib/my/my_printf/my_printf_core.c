/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Reimplementation of the printf function from the standard lib
*/

#include "my_printf.h"
#include "../my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int get_type_by_spec(char spec)
{
    int type = TYPE_NOTHING;

    type = (spec == 'd' || spec == 'i') ? TYPE_INT : type;
    type = (spec == 'u') ? TYPE_UINT : type;
    type = (spec == 'o') ? TYPE_UINT : type;
    type = (spec == 'x') ? TYPE_UINT : type;
    type = (spec == 'X') ? TYPE_UINT : type;
    type = (spec == 'c') ? TYPE_INT : type;
    type = (spec == 's' || spec == 'S') ? TYPE_STR : type;
    type = (spec == 'p') ? TYPE_VOID : type;
    type = (spec == 'b') ? TYPE_UINT : type;
    type = (spec == '%') ? TYPE_NOTHING : type;
    return (type);
}

void *get_flag_function(flag_t *flag)
{
    char *(*fptr[12])() = {&putnbr_pf, &putnbr_pf, &unsigned_int, &octal, \
    &unsigned_hex, &unsigned_hex_uppercase, (char *(*)())&putchar_pf, \
    &putstr_pf, &show_str_octal, &pointer_addr, &unsigned_bin, &print_percent};
    char *(*result)();
    char *flags = "diuoxXcsSpb%";

    for (int c = 0; c < 12; c++) {
        if (flag->spec == flags[c])
            result = fptr[c];
    }
    if (is_in(flag->spec, "id") && flag->type == TYPE_LONG)
        result = &my_put_long;
    if (is_in(flag->spec, "id") && flag->type == TYPE_LONG_LONG)
        result = &my_put_long_long;
    if (is_in(flag->spec, "u") && flag->type == TYPE_ULONG)
        result = &unsigned_long;
    if (is_in(flag->spec, "u") && flag->type == TYPE_ULONG_LONG)
        result = &unsigned_long_long;
    return ((void *)result);
}

int process_bad_spec(flag_t *flag, pftarget_t *target)
{
    if (target->format[flag->pos] != '\0') {
        my_putchar('%');
        my_putchar(target->format[flag->pos]);
        target->chars_written += 2;
    }
    return (1);
}

void process_flag(flag_t *flag, va_list *list, pftarget_t *target)
{
    char *(*fptr)();
    char *res = NULL;

    if (flag->spec == 0 && process_bad_spec(flag, target))
        return;
    if (flag->type == -1)
        flag->type = get_type_by_spec(flag->spec);
    fptr = get_flag_function(flag);
    res = flag->type == TYPE_INT ? fptr(va_arg(*list, int)) : res;
    res = flag->type == TYPE_UINT ? fptr(va_arg(*list, unsigned int)) : res;
    res = flag->type == TYPE_LONG ? fptr(va_arg(*list, long)) : res;
    res = flag->type == TYPE_ULONG ? fptr(va_arg(*list, unsigned long)) : res;
    res = flag->type == TYPE_LONG_LONG ? fptr(va_arg(*list, long long)) : res;
    res = flag->type == TYPE_ULONG_LONG ?
    fptr(va_arg(*list, unsigned long long)) : res;
    res = flag->type == TYPE_STR ? fptr(va_arg(*list, char *)) : res;
    res = flag->type == TYPE_VOID ? fptr(va_arg(*list, void *)) : res;
    res = flag->type == TYPE_NOTHING ? fptr() : res;
    put_result(flag, res, target);
    free(res);
}
