/*
** EPITECH PROJECT, 2021
** my_is_letter
** File description:
** Function that returns 1 if a char is a letter, else 0
*/

int my_is_letter(char c)
{
    if (c >= 65 && c <= 90)
        return (1);
    else if (c >= 97 && c <= 122)
        return (1);
    return (0);
}
