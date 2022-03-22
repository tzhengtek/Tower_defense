/*
** EPITECH PROJECT, 2021
** my_compute_power_it.c
** File description:
** 11:38
*/

int my_compute_power_it(int nb, int p);

int my_compute_power_it(int nb, int p)
{
    int i = 1;
    int nb2 = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    while (i < p) {
        nb *= nb2;
        i++;
    }
    return (nb);
}
