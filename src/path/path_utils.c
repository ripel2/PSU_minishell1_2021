/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int path_is_absolute(char *path)
{
    if (my_strlen(path) > 0 && path[0] == '/')
        return (1);
    for (int c = 0; path[c] != 0; c++)
        if (path[c] == '/')
            return (1);
    return (0);
}

int path_exists(char *path)
{
    struct stat buf;

    return (stat(path, &buf) == 0);
}

int path_is_file(char *path)
{
    struct stat buf;

    if (stat(path, &buf) != 0)
        return (0);
    return (S_ISREG(buf.st_mode));
}

int path_is_dir(char *path)
{
    struct stat buf;

    if (stat(path, &buf) != 0)
        return (0);
    return (S_ISDIR(buf.st_mode));
}
