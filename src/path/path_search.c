/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

char *path_cat(char *pdir, char *path)
{
    char *res;
    char *tmp;

    if (my_strlen(pdir) > 0)
        tmp = my_strcat_m(pdir, "/");
    else
        tmp = my_strcpy_m("");
    res = my_strcat_m(tmp, path);
    free(tmp);
    return (res);
}

char *get_search_path(char *given_path, char **paths)
{
    char *tmp;

    for (int c = 0; paths[c] != 0; c++) {
        tmp = path_cat(paths[c], given_path);
        if (path_exists(tmp) && path_is_file(tmp))
            return (tmp);
        free(tmp);
    }
    return (NULL);
}

char *search_in_current_dir(char *given_path)
{
    char *chdir = malloc(sizeof(char) * 4096);
    char *tmp;

    getcwd(chdir, 4096);
    if (chdir == NULL)
        return (NULL);
    tmp = path_cat(chdir, given_path);
    if (path_exists(tmp) && path_is_file(tmp)) {
        free(chdir);
        return (tmp);
    }
    free(tmp);
    free(chdir);
    return (NULL);
}

char *search_for_exec(char *given_path, char **env)
{
    char *path = get_env_value(env, "PATH");
    char **paths = NULL;
    char *result = NULL;

    paths = split_str(path, ":");
    result = get_search_path(given_path, paths);
    if (paths != NULL)
        free_array(paths);
    return (result);
}
