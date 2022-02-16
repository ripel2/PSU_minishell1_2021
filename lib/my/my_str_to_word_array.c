/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Function that splits a string into an array of words.
*/

#include <stdlib.h>
#include "my.h"

void add_last_word(char **dest, int dest_c, char *start, char *pos)
{
    char *word = malloc(sizeof(char) * (pos - start + 1));

    my_strcpy(word, start);
    dest[dest_c] = word;
    if (start != pos)
        dest[dest_c + 1] = NULL;
}

char **my_str_to_word_array(char const *str)
{
    int strlen = my_strlen(str);
    char **dest = malloc(sizeof(char) * (strlen + 1));
    char *start = str;
    char *pos = str;
    char *word = NULL;
    int dest_c = 0;

    for (; *pos; pos++) {
        if (my_is_letter(*pos) == 0 && my_is_nbr(*pos) == 0) {
            word = malloc(sizeof(char) * (pos - start + 1));
            my_strncpy(word, start, pos - start);
            dest[dest_c] = word;
            dest_c++;
            pos++;
            start = pos;
        }
    }
    add_last_word(dest, dest_c, start, pos);
    return (dest);
}
