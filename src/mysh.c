/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

const int (*EXECUTE_FUNCTION[2])(char ***env, char **args, int *last) = {
    execute_command, execute_builtin
};

int process_comand(char *cmd, char ***env, int *last)
{
    int temp_status = 0;
    char **args;

    if (cmd == NULL)
        return (-MALLOC_ERROR);
    if (my_strlen(cmd) == 0 || (my_strlen(cmd) == 1 && cmd[0] == '\n'))
        return (NO_ERRORS);
    args = parse_command(cmd);
    if (args == NULL || *args == NULL)
        return (NO_ERRORS);
    temp_status = EXECUTE_FUNCTION[is_builtin(args)](env, args, last);
    if (temp_status >= 0)
        *last = temp_status;
    free_array(args);
    if (temp_status < 0)
        return (temp_status);
    return (NO_ERRORS);
}

int exit_sh(char *cmd, int last)
{
    if (isatty(0) != 0)
        my_printf("\nexit\n");
    free(cmd);
    return (last);
}

int receive_commands(char ***env, int *last)
{
    size_t cmd_length = 1024 * 4 + 2;
    char *cmd = NULL;
    size_t chars_read = 0;
    int command_status = 0;

    while (chars_read != -1) {
        print_prompt(*env);
        bind_sigint(0);
        chars_read = getline(&cmd, &cmd_length, stdin);
        if (chars_read == -1)
            return (exit_sh(cmd, *last));
        command_status = process_comand(cmd, env, last);
        if (command_status == -MALLOC_ERROR)
            return (MALLOC_ERROR);
        if (command_status == EXIT_BUILTIN_CODE)
            break;
    }
    free(cmd);
    return (NO_ERRORS);
}

int mysh(char *program_name, char **env)
{
    int last_exec_status = 0;
    char **dupenv = array_dup(env);
    int mysh_status = receive_commands(&dupenv, &last_exec_status);

    free_array(dupenv);
    if (mysh_status != 0) {
        print_error(program_name, mysh_status);
        return (1);
    }
    return (last_exec_status);
}
