/*
** EPITECH PROJECT, 2021
** my_showstr
** File description:
** Shows a string and replaces its non printable characters with
** an hexadecimal representation.
*/

#include "my.h"

void my_put_hex(char c)
{
    int copy = c;
    int div;
    int x = 3;
    char str[4];

    while (copy > 0) {
        div = copy % 16;
        if (div >= 0 && div <= 9)
            str[x--] = '0' + div;
        else
            str[x--] = 'a' + div - 10;
        copy = copy / 16;
    }
    if (c < 16)
        str[x--] = '0';
    str[x--] = '\\';
    my_putstr(str);
}

int my_showstr(char const *str)
{
    while (*str != '\0') {
        if (*str < ' ' || *str > 127)
            my_put_hex(*str);
        else
            my_putchar(*str);
        str++;
    }
    return (0);
}
