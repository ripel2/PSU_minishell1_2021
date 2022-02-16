/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** Function that returns 1 if the string is lowerstring
** only else 0
*/

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if (*str < 32 || *str > 127)
            return (0);
        str++;
    }
    return (1);
}
