/*
** EPITECH PROJECT, 2021
** tab
** File description:
** functions to create and manipulate arrays
*/

#pragma once

int char_isin(char ch, char *chars);
int count_separators(char *str, char *separators);
char **split_str(char *str, char *separators);

int array_len(char **tab);
void free_array(char **words);
