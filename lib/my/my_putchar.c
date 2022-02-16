/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** A program to put a character on the screen.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
