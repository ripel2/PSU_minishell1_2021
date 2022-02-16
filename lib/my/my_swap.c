/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swaps the contents of two integers using pointers.
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
