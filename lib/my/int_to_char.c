/*
** EPITECH PROJECT, 2021
** int_to_char.c
** File description:
** int_to_char
*/

/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** oya oya oya
*/

#include <stdlib.h>

#include <unistd.h>

void my_putchar(char c);

char *int_to_char(int nb)
{
    int power = 0;
    int i = 1;
    int p = 0;
    int j = 0;
    char *str = NULL;

    for (i; i <= nb / 10; i *= 10)
        power++;
    str = malloc(sizeof(char) * (power + 2));
    for (int start = 0; start != power + 1; start++) {
        p = (nb / i);
        nb = nb - (p * i);
        i /= 10;
        str[j] = p + '0';
        j++;
    }
    str[j] = '\0';
    return str;
}
