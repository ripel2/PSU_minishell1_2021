/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1 main
*/

#include "mysh.h"

char *my_strdup(char const *src)
{
    int slen = my_strlen(src);
    char *newstr = malloc(sizeof(char) * (slen + 1));
    int c;

    if (newstr == NULL)
        return (NULL);
    for (c = 0; c < slen; c++)
        newstr[c] = src[c];
    newstr[c] = '\0';
    return (newstr);
}
