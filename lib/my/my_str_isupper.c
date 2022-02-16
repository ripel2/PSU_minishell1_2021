/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** Function that returns 1 if the string is upperstring
** only else 0
*/

int my_str_isupper(char const *str)
{
    while (*str != '\0') {
        if (*str < 'A' || *str > 'Z')
            return (0);
        str++;
    }
    return (1);
}
