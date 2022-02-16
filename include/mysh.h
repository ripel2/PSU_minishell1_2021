/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** Header to include add of the lib functions
*/

#pragma once

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#include "errors.h"
#include "my.h"
#include "tab.h"

#define EXIT_BUILTIN_CODE -999

typedef __sighandler_t sighandler_t;
#define DEFAULT_ENV __environ

char *my_strdup(char const *src);
char **array_dup(char **array);

int mysh(char *program_name, char **env);
char **parse_command(char *command);

void print_prompt(char **env);
char *get_current_dir(void);

void print_exec_error(int signum, int core_dumped);
void print_execve_error(char *exec_name, int err_no);

char *search_for_exec(char *given_path, char **env);

int path_is_absolute(char *path);
int path_exists(char *path);
int path_is_file(char *path);
int path_is_dir(char *path);

char *get_env_value(char **env, char *key);
int add_var(char ***env, char *var);
int add_var_from_key(char ***env, char *key, char *data);
int remove_var(char ***env, char *key);

int execute_command(char ***env, char **args, int *last);

int is_builtin(char **args);
int execute_builtin(char ***env, char **args, int *last);

int env_builtin(char ***env, char **args, int *last);
int setenv_builtin(char ***env, char **args, int *last);
int unsetenv_builtin(char ***env, char **args, int *last);

int exit_builtin(char ***env, char **args, int *last);
int cd_builtin(char ***env, char **args, int *last);

sighandler_t bind_sigint(int func);
