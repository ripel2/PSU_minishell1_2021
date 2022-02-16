/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** Function that computes the square root of a number and
** returns it, only if the result is a whole number.
** Otherwise returns 0.
*/

int my_compute_square_root(int nb)
{
    int result = 1;
    int power = 1;

    while (power < nb) {
        result++;
        power = result * result;
    }
    if (nb == power)
        return (result);
    else
        return (0);
}
