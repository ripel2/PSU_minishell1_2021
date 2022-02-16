/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** Function that capitalizes the first letter of each word in a text
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    char *pos = str;
    int upper = 1;

    for (; *pos != '\0'; pos++) {
        if (upper == 1) {
            *pos = char_to_uppercase(*pos);
            upper = 0;
        } else {
            *pos = char_to_lowercase(*pos);
        }
        if (my_is_letter(*pos) == 0) {
            upper = 1;
        }
    }
    return (str);
}
