/*
** EPITECH PROJECT, 2021
** print_pointer.c
** File description:
** Function to print a pointer address
*/

#include "my_printf.h"
#include "../my.h"
#include <stddef.h>

char *pointer_addr(void *ptr)
{
    char *res;
    if (ptr != NULL) {
        res = my_putunbr_base((unsigned long long)ptr, "0123456789abcdef");
        res = my_strcat_m("0x", res);
    } else {
        res = my_strcpy_m("(nil)");
    }
    return (res);
}
