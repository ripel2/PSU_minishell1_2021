/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Reimplementation of the printf function from the standard lib
*/

#include "my_printf.h"
#include "../my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int my_printf(const char *format, ...)
{
    va_list list;
    flag_t *cflag;
    pftarget_t target = {format, my_strlen(format), 0, 1};

    va_start(list, format);
    for (int c = 0; c < target.format_len; c++) {
        if (format[c] == '%' && format[c + 1] != '\0') {
            c++;
            cflag = parse_flag(format, &c);
            process_flag(cflag, &list, &target);
            free(cflag);
        } else if (format[c] != '%' && c < target.format_len) {
            write(1, &format[c], 1);
            target.chars_written++;
        }
    }
    va_end(list);
    return (target.chars_written);
}

int my_dprintf(int fd, const char *format, ...)
{
    va_list list;
    flag_t *cflag;
    pftarget_t target = {format, my_strlen(format), 0, fd};

    va_start(list, format);
    for (int c = 0; c < target.format_len; c++) {
        if (format[c] == '%' && format[c + 1] != '\0') {
            c++;
            cflag = parse_flag(format, &c);
            process_flag(cflag, &list, &target);
            free(cflag);
        } else if (format[c] != '%' && c < target.format_len) {
            write(fd, &format[c], 1);
            target.chars_written++;
        }
    }
    va_end(list);
    return (target.chars_written);
}
