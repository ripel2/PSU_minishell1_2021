/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int array_len(char **tab)
{
    int pos = 0;
    int counter = 0;

    while (*(tab + pos) != 0) {
        counter++;
        pos += 1;
    }
    return (counter);
}

void free_array(char **words)
{
    for (int c = 0; words[c] != 0; c++)
        free(words[c]);
    free(words);
}

int char_isin(char ch, char *chars)
{
    for (int i = 0; i < my_strlen(chars); i++)
        if (chars[i] == ch)
            return (1);
    return (0);
}

char **array_dup(char **array)
{
    char **res = NULL;
    int c = 0;

    if (array == NULL)
        return (res);
    res = malloc(sizeof(char *) * (array_len(array) + 1));
    if (res == NULL)
        return (res);
    while (array[c] != NULL) {
        res[c] = my_strdup(array[c]);
        if (res[c] == NULL)
            return (NULL);
        c++;
    }
    res[c] = NULL;
    return (res);
}
