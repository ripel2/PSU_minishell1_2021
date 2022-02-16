/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1 main
*/

#include "mysh.h"

void put_prompt(int signum)
{
    my_printf("\n");
    print_prompt(DEFAULT_ENV);
}

void kill_process(int signum)
{
    kill(getpid(), SIGCHLD);
    my_dprintf(2, "\n");
}

sighandler_t bind_sigint(int func)
{
    void *sigint_handler[] = {put_prompt, kill_process};

    return (signal(SIGINT, sigint_handler[func]));
}
