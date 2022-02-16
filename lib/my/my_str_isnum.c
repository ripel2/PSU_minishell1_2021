/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** Function that returns 1 if the string is a number
** only else 0
*/

int my_str_isnum(char const *str)
{
    while (*str != '\0') {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}
