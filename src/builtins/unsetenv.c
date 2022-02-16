/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int unsetenv_builtin(char ***env, char **args, int *last)
{
    char *temp;

    if (array_len(args) < 2) {
        my_dprintf(2, "unsetenv: Too few arguments.\n");
        return (1);
    }
    for (int c = 1; args[c] != 0; c++) {
        temp = get_env_value(*env,  args[c]);
        if (temp != NULL) {
            remove_var(env, args[c]);
        }
    }
    return (NO_ERRORS);
}
