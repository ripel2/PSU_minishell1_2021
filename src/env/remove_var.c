/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int remove_var(char ***env, char *key)
{
    char **result = malloc(sizeof(char *) * (array_len(*env) + 1));
    int c = 0;
    int d = 0;

    key = my_strcat_m(key, "=");
    if (result == NULL)
        return (MALLOC_ERROR);
    while ((*env) != NULL && (*env)[c] != NULL) {
        if (my_strncmp(key, (*env)[c], my_strlen(key)) != 0) {
            result[d] = (*env)[c];
            d++;
        } else
            free((*env)[c]);
        c++;
    }
    result[d] = NULL;
    free(*env);
    free(key);
    *env = result;
    return (NO_ERRORS);
}
