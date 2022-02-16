/*
** EPITECH PROJECT, 2021
** my_lib
** File description:
** Header to include add of the lib functions
*/

#pragma once

int my_compute_power_rec(int, int);
int my_compute_square_root(int);

int my_find_prime_sup(int);

int my_getnbr(char const *);

int my_is_letter(char);
int my_is_nbr(char);

int my_is_prime(int);
int my_isneg(int);

void my_put_nbr(int);
void put_max_neg(void);
void my_putchar(char);
void my_putstr(char const *);
void my_putstr_err(char const *);
char *my_revstr(char *);

int my_showmem(char const *, int);

int my_showstr(char const *);

void my_sort_int_array(int *, int);

int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);

char *my_strcapitalize(char *);
char *my_strlowcase(char *);
char *my_strupcase(char *);

char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);

int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);

int my_strlen(char const *);

char *my_strstr(char *, char const *);

void my_swap(int *, int *);

int my_show_word_array(char * const *);

int character_is_valid(char);
int character_to_digit(char);
int my_is_prime_divider(int, int);
void my_put_hex(char c);
char char_to_lowercase(char);
char char_to_uppercase(char);

int my_printf(const char *format, ...);
int my_dprintf(int fd, const char *format, ...);

char *my_strcat_m(char *str1, char *str2);
char *my_strcpy_m(char *str);
