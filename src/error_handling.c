/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1 error handling
*/

#include "mysh.h"

void print_error(char *program_name, int return_code)
{
    char *errors[2] = {"no error", "malloc error"};

    my_dprintf(2, "%s: %s\n", program_name, errors[return_code]);
}
