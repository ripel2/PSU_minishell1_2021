/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int get_execve(char *executable, char **args, char **env)
{
    int child_pid = fork();
    int child_status = 0;

    if (child_pid == 0) {
        if (execve(executable, args, env) < 0)
            print_execve_error(args[0], errno);
        return (0);
    } else {
        waitpid(child_pid, &child_status, 0);
        if (WIFSIGNALED(child_status) && WTERMSIG(child_status) != SIGINT)
            print_exec_error(WTERMSIG(child_status), WCOREDUMP(child_status));
        return (WEXITSTATUS(child_status));
    }
}

int has_error(char *executable, char **args)
{
    if (executable == NULL) {
        my_printf("%s: Command not found.\n", args[0]);
        return (1);
    }
    if (access(executable, X_OK) < 0) {
        my_printf("%s: Permission denied.\n", args[0]);
        return (1);
    }
    if (path_is_dir(executable)) {
        my_printf("%s: Permission denied.\n"
        "%s: Is a directory.\n", args[0], args[0]);
        return (1);
    }
    return (0);
}

int execute_command(char ***env, char **args, int *last)
{
    int child_status = 0;
    char *executable = NULL;

    if (path_is_absolute(args[0]) == 0) {
        executable = search_for_exec(args[0], *env);
    } else if (path_exists(args[0])) {
        executable = my_strdup(args[0]);
    }
    if (has_error(executable, args)) {
        free(executable);
        return (1);
    } else {
        bind_sigint(1);
        child_status = get_execve(executable, args, *env);
    }
    free(executable);
    return (child_status);
}
