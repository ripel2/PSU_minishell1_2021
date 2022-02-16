
# Minishell1

A shell with minimal functionality coded in C

## About this project

This is the first of three projects where we have to implement a shell in C.
The reference is the tcsh shell. See https://github.com/tcsh-org/tcsh

## How to use

First compile with the Makefile

```sh
make
```

Then launch the shell by typing
```sh
./mysh
```

It also supports receiving commands with a pipe. For example :
```sh
echo "ls" | ./mysh
```
will work.

To exit the shell, use the command `exit` or Ctrl+D

## Features

- Run commands with basic arguments (e.g `/bin/ls -l -a`)
- Run commands with path in the environment variable "PATH" (e.g `ls`)
- Builtins `cd`, `exit`, `env`, `setenv` and `unsetenv`
- Exit with Ctrl+D
- Terminate program with Ctrl+C
