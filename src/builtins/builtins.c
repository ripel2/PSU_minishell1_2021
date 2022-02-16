/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

const char *BUILTIN_NAMES[] = {
    "exit", "cd", "env", "setenv", "unsetenv", 0
};

const int (*BUILTIN_FUNCTIONS[5])(char ***env, char **args, int *last) = {
    exit_builtin, cd_builtin, env_builtin, setenv_builtin, unsetenv_builtin
};

int is_builtin(char **args)
{
    if (array_len(args) == 0)
        return (0);
    for (int c = 0; BUILTIN_NAMES[c] != 0; c++) {
        if (my_strcmp(args[0], BUILTIN_NAMES[c]) == 0)
            return (1);
    }
    return (0);
}

int execute_builtin(char ***env, char **args, int *last)
{
    for (int c = 0; BUILTIN_NAMES[c] != 0; c++) {
        if (my_strcmp(args[0], BUILTIN_NAMES[c]) == 0)
            return (BUILTIN_FUNCTIONS[c](env, args, last));
    }
    return (0);
}
