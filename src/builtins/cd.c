/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

char *cd_get_error(char **args)
{
    if (array_len(args) > 2)
        return ("cd: Too many arguments.\n");
    return (NULL);
}

int cd_go_to_home_path(char **env)
{
    char *home = get_env_value(env, "HOME");

    if (home == NULL) {
        my_dprintf(2, "cd: %s\n", "No home directory.");
        return (NO_ERRORS);
    }
    if (chdir(home) < 0) {
        my_dprintf(2, "cd: %s\n", "Can't change to home directory.");
        return (NO_ERRORS);
    }
    return (NO_ERRORS);
}

int cd_change_directory(char **env, char **args)
{
    char *dir = args[1];

    if (my_strcmp(args[1], "-") == 0)
        dir = get_env_value(env, "OLDPWD");
    if (dir == NULL) {
        my_dprintf(2, ": %s\n", strerror(ENOENT));
        return (NO_ERRORS);
    }
    if (path_is_dir(dir) != 1) {
        my_dprintf(2, "%s: Not a directory.\n", dir);
        return (NO_ERRORS);
    }
    if (chdir(dir) < 0) {
        my_dprintf(2, "%s: %s\n", dir, strerror(errno));
        return (NO_ERRORS);
    }
    return (NO_ERRORS);
}

int change_env_pwd(char ***env, char **args, char *old_dir)
{
    char new_dir[4097] = {0};

    getcwd(new_dir, 4097);
    if (remove_var(env, "PWD") == MALLOC_ERROR)
        return (-MALLOC_ERROR);
    if (remove_var(env, "OLDPWD") == MALLOC_ERROR)
        return (-MALLOC_ERROR);
    if (add_var_from_key(env, "PWD", new_dir) == MALLOC_ERROR)
        return (-MALLOC_ERROR);
    if (add_var_from_key(env, "OLDPWD", old_dir) == MALLOC_ERROR)
        return (-MALLOC_ERROR);
    return (NO_ERRORS);
}

int cd_builtin(char ***env, char **args, int *last)
{
    char old_dir[4097] = {0};
    int subcommand_status = 0;

    getcwd(old_dir, 4097);
    if (cd_get_error(args) != NULL) {
        my_dprintf(2, cd_get_error(args));
        return (NO_ERRORS);
    }
    if (array_len(args) == 1)
        subcommand_status = cd_go_to_home_path(*env);
    else
        subcommand_status = cd_change_directory(*env, args);
    if (subcommand_status != 0)
        return (subcommand_status);
    return (change_env_pwd(env, args, old_dir));
}
