/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

char *dup_current_dir(char *todup)
{
    char *res = malloc(sizeof(char) * (my_strlen(todup) + 1));

    my_strcpy(res, todup);
    res[my_strlen(todup)] = 0;
    return (res);
}

char *get_current_dir(void)
{
    char buf[4097] = {0};
    char **arr;
    int len;
    char *result;

    if (buf == NULL)
        return (NULL);
    if (getcwd(buf, 4096) < 0)
        return (NULL);
    arr = split_str(buf, "\\/");
    if (arr == NULL)
        return (NULL);
    len = array_len(arr);
    if (len > 0)
        result = dup_current_dir(arr[len - 1]);
    else
        result = my_strdup(buf);
    free_array(arr);
    return (result);
}

void print_prompt_isatty(char **env)
{
    char *userentry = get_env_value(env, "USER");
    char *hostentry = get_env_value(env, "HOSTNAME");
    char *username = userentry ? userentry : "username";
    char *hostname = hostentry ? hostentry : "host";
    char *cwd = get_current_dir();

    if (cwd == NULL)
        cwd = "path";
    my_putstr("\e[38;5;51m[");
    my_putstr(username);
    my_putstr("@");
    my_putstr(hostname);
    my_putstr(" ");
    my_putstr(cwd);
    my_putstr("]\e[0m$ ");
    free(cwd);
}

void print_prompt(char **env)
{
    if (isatty(0) != 0) {
        print_prompt_isatty(env);
    }
}
