/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** Function that returns 1 if a given number is prime, otherwise 0.
*/

int my_is_prime_divider(int nb, int divider)
{
    if (nb % divider == 0)
        return (0);
    else if (divider * divider > nb)
        return (1);
    return my_is_prime_divider(nb, divider + 1);
}

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    else if (nb == 2)
        return (1);
    return my_is_prime_divider(nb, 2);
}
