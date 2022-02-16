/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** Displays an array of words.
*/

#include <stdlib.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int c;

    for (c = 0; tab[c] != 0; c++) {
        my_putstr(tab[c]);
        my_putchar('\n');
    }
    return (0);
}
