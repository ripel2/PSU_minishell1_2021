##
## EPITECH PROJECT, 2021
## minishell1
## File description:
## Makefile for the minishell1 project
##

DEFAULT     =   "\033[00m"
RED         =   "\033[31m"
GREEN       =   "\033[1;32m"
TEAL        =   "\033[1;36m"
YELLOW      =   "\033[1;7;25;33m"
MAGENTA     =   "\033[1;3;4;35m"
YELLOW      =   "\033[5;7;1;31m"
BLINK       =   "\033[5m"
END         =   "\n"

NAME = mysh

SRC = src/mysh.c \
	src/parsing/parser.c \
	src/builtins/builtins.c \
	src/builtins/cd.c \
	src/builtins/exit.c \
	src/builtins/env.c \
	src/builtins/setenv.c \
	src/builtins/unsetenv.c \
	src/path/path_utils.c \
	src/path/path_search.c \
	src/path/print_prompt.c \
	src/env/get_env_value.c \
	src/env/add_var.c \
	src/env/remove_var.c \
	src/array_utils.c \
	src/split_str.c \
	src/status_error.c \
	src/error_handling.c \
	src/execute_command.c \
	src/term_signal.c \
	src/my_strdup.c

MAIN = src/main.c

MAINOBJ = src/main.o

CFLAGS = -Llib -lmy -Wall -Iinclude

TESTS_FLAGS = -lcriterion -fprofile-arcs -ftest-coverage --coverage

CC = gcc

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	printf $(GREEN)"[+] Compiled $@ "$(DEFAULT)"\n" || \
	printf $(RED)"[-] Failed compiling $@ "$(DEFAULT)"\n"

all: $(NAME) clean

$(NAME): $(OBJ) $(MAINOBJ)
	@make -C lib/my > /dev/null
	@$(CC) -o $(NAME) $(OBJ) $(MAINOBJ) $(CFLAGS) && \
	printf $(GREEN)"[+] Compiled "$(NAME)" "$(DEFAULT)"\n" || \
	printf $(RED)"[-] Failed compiling "$(NAME)" "$(DEFAULT)"\n"

clean:
	@find . -name "*~" -delete -or -name "#*#" -delete
	@find . -name "*.o" -delete
	@find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
