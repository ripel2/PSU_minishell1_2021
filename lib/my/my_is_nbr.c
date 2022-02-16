/*
** EPITECH PROJECT, 2021
** my_is_nbr
** File description:
** Function that returns 1 if a char is a number, else 0
*/

int my_is_nbr(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}
