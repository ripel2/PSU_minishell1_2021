/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** Function that returns the smallest prime number that is
** greater or equal than a given number.
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1)
        return (nb);
    else
        return (my_find_prime_sup(nb + 1));
}
