/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** Function that returns 1 if the string is lowerstring
** only else 0
*/

int my_str_islower(char const *str)
{
    while (*str != '\0') {
        if (*str < 'a' || *str > 'z')
            return (0);
        str++;
    }
    return (1);
}
