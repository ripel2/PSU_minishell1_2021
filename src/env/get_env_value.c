/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

char *get_value_from_key(char **env, int index)
{
    int c = 0;

    while (env[index][c] != '=')
        c++;
    return (&env[index][c + 1]);
}

char *get_env_value(char **env, char *key)
{
    for (int c = 0; env[c] != 0; c++) {
        if (my_strncmp(key, env[c], my_strlen(key)) == 0 &&
        env[c][my_strlen(key)] == '=')
            return (get_value_from_key(env, c));
    }
    return (NULL);
}
