/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

void print_execve_error(char *exec_name, int err_no)
{
    char enoexex_msg[] = "Exec format error. Wrong Architecture.";

    if (err_no == ENOEXEC)
        my_dprintf(2, "%s: %s\n", exec_name, enoexex_msg);
    else
        my_dprintf(2, "%s: %s\n", exec_name, strerror(err_no));
}

void print_exec_error(int signum, int core_dumped)
{
    if (signum == SIGFPE)
        my_dprintf(2, "Floating exception");
    else
        my_dprintf(2, strsignal(signum));
    if (core_dumped)
        my_dprintf(2, " (core dumped)");
    my_dprintf(2, "\n");
}
