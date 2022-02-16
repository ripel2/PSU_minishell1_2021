/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Copy of the strcmp function
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (; *s1 == *s2; s1++, s2++)
        if (*s1 == '\0')
            return (0);
    if (*s1 < *s2)
        return (-1);
    return (1);
}
