/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** getnumber
*/

#include <stdio.h>

void my_putchar(char c);

int my_getnbr(char *str);

int my_compute_power_it(int nb, int p);

void my_put_nbr(int nb);

int my_strlen(char *str);

int str_is_neg(char str, int neg)
{
    if (str == '-')
        neg = -neg;
    return neg;
}

int str_num(char str)
{
    if (str >= '0' && str <= '9')
        return 1;
    else
        return 0;
}

int print_my_number(char const *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str_num(str[i]) == 1)
            counter++;
        else if (counter != 0)
            return counter;
    }
    return counter;
}

int my_getnbr(char *new_str)
{
    long p = 0;
    int neg = 1;
    int last_num;
    int power = print_my_number(new_str) - 1;

    for (int i = 0; new_str[i] != '\0'; i++) {
        neg = str_is_neg(new_str[i], neg);
        if (str_num(new_str[i]) == 1 && str_num(new_str[i + 1]) == 1) {
            p += (new_str[i] - '0') * my_compute_power_it(10, power);
            power--;
        } else if (str_num(new_str[i]) == 1 && str_num(new_str[i + 1]) == 0) {
            p += (new_str[i] - '0') * my_compute_power_it(10, power);
            last_num = neg * p;
            return last_num;
        }
    }
}
