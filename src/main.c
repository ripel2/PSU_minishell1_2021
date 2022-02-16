/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1 main
*/

#include "mysh.h"

void put_usage(char *name)
{
    my_printf("USAGE\n");
    my_printf("\t%s\n\n", name);
    my_printf("DESCRIPTION\n");
    my_printf("\tBasic shell coded in C\n");
}

int needs_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (1);
    return (0);
}

int main(int ac, char **av, char **env)
{
    int return_code = 0;

    if (needs_help(ac, av)) {
        put_usage(av[0]);
        return (0);
    }
    if (ac > 1)
        return (84);
    return_code = mysh(av[0], env);
    return (return_code);
}
