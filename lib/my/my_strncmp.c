/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** Copy of the strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (n > 0 && *s1 != '\0' && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return (0);
    return (*s1 - *s2);
}
