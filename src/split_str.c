/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include "mysh.h"

int count_separators(char *str, char *separators)
{
    int spaces = 0;
    int got_space = 0;

    for (int c = 0; str[c] != '\0'; c++) {
        got_space = 0;
        while (char_isin(str[c], separators)) {
            got_space = 1;
            c++;
        }
        if (got_space)
            spaces++;
    }
    return (spaces);
}

int skip_space(char *str, int *c, int word_start, char *separators)
{

    while (char_isin(str[*c], separators) && str[*c] != '\0') {
        if (*c > my_strlen(str))
            break;
        (*c)++;
    }
    return (*c);
}

char *get_word(char *str, int word_start, int word_end)
{
    int length = word_end - word_start;
    char *word = malloc(sizeof(char) * (length + 1));
    int i = 0;

    if (word == NULL)
        return (NULL);
    for (int c = word_start; c < word_start + length; c++)
        word[i++] = str[c];
    word[i] = '\0';
    return (word);
}

void split_end(char ***words, int cword)
{
    (*words)[cword] = 0;
    cword--;
    while (cword >= 0) {
        if ((*words)[cword] == NULL)
            *words = NULL;
        cword--;
    }
}

char **split_str(char *str, char *separators)
{
    int c;
    int cword = 0;
    int word_start = 0;
    int length = my_strlen(str);
    int sep_count = count_separators(str, separators);
    char **words = malloc(sizeof(char *) * (sep_count + 2));

    if (words == NULL)
        return (NULL);
    for (c = 0; str[c] != '\0'; c++) {
        if (char_isin(str[c], separators) && c != 0) {
            words[cword++] = get_word(str, word_start, c);
            word_start = skip_space(str, &c, length, separators);
        } else if (char_isin(str[c], separators))
            word_start = skip_space(str, &c, length, separators);
    }
    if (c <= length)
        words[cword++] = get_word(str, word_start, c);
    split_end(&words, cword);
    return (words);
}
