/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

char **parse_command(char *command)
{
    int len = my_strlen(command);
    char **args;

    if (command[len - 1] == '\n')
        command[len - 1] = '\0';
    args = split_str(command, " \t");
    if (args == NULL)
        my_dprintf(2, ": malloc error\n");
    return (args);
}
