/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int add_var(char ***env, char *var)
{
    char **result = malloc(sizeof(char *) * (array_len(*env) + 2));
    int c = 0;

    if (result == NULL)
        return (MALLOC_ERROR);
    if ((*env) != NULL) {
        while ((*env)[c] != NULL) {
            result[c] = (*env)[c];
            c++;
        }
    }
    result[c++] = var;
    result[c] = '\0';
    free(*env);
    *env = result;
    return (NO_ERRORS);
}

int add_var_from_key(char ***env, char *key, char *data)
{
    int size = my_strlen(key) + 1 + my_strlen(data) + 1;
    char *var;
    int c = 0;

    if (key == NULL || my_strlen(key) == 0)
        return (NO_ERRORS);
    var = malloc(sizeof(char) * size);
    if (var == NULL)
        return (MALLOC_ERROR);
    for (int d = 0; key[d] != '\0'; d++)
        var[c++] = key[d];
    var[c++] = '=';
    for (int d = 0; data[d] != '\0'; d++)
        var[c++] = data[d];
    var[c] = '\0';
    return (add_var(env, var));
}
