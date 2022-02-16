/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

char *setenv_get_error(char **args)
{
    if (array_len(args) > 3)
        return ("setenv: Too many arguments.\n");
    if (my_is_letter(args[1][0]) == 0)
        return ("setenv: Variable name must begin with a letter.\n");
    for (int c = 0; args[1][c] != '\0'; c++) {
        if (my_is_nbr(args[1][c]) == 0 && my_is_letter(args[1][c]) == 0
        && args[1][c] != '_')
            return ("setenv: Variable name must contain "
            "alphanumeric characters.\n");
    }
    return (NULL);
}

int setenv_builtin(char ***env, char **args, int *last)
{
    char *val;
    char *data;

    if (array_len(args) == 1)
        return (env_builtin(env, args, NULL));
    if (setenv_get_error(args) != NULL) {
        my_dprintf(2, setenv_get_error(args));
        return (1);
    }
    val = get_env_value(*env, args[1]);
    data = args[2] == NULL ? "" : args[2];
    if (val == NULL) {
        add_var_from_key(env, args[1], data);
    } else {
        remove_var(env, args[1]);
        add_var_from_key(env, args[1], data);
    }
    return (NO_ERRORS);
}
