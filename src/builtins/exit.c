/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int exit_builtin(char ***env, char **args, int *last)
{
    if (array_len(args) > 2) {
        my_dprintf(2, "exit: Too much arguments\n");
        return (1);
    }
    if (isatty(0) != 0)
        my_printf("exit\n");
    if (array_len(args) == 2 && my_str_isnum(args[1])) {
        *last = my_getnbr(args[1]);
    } else if (array_len(args) == 2) {
        my_dprintf(2, "exit: Syntax error. Exit needs a number\n");
    }
    return (EXIT_BUILTIN_CODE);
}
