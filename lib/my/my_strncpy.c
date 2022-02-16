/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Function that copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int strlen;
    int c;

    for (strlen = 0; src[strlen] != '\0'; strlen++)
        strlen++;
    for (c = 0; c < n; c++) {
        dest[c] = src[c];
        if (c > strlen)
            dest[c] = '\0';
    }
    return (dest);
}
