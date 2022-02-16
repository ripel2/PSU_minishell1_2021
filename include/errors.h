/*
** EPITECH PROJECT, 2021
** errors
** File description:
** custom ints to handle errors
*/

#pragma once

typedef enum errors {
    NO_ERRORS = 0,
    MALLOC_ERROR
} errors_t;

void print_error(char *program_name, int return_code);
