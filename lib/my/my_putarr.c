/*
** EPITECH PROJECT, 2022
** my_putarr.c
** File description:
** my_putarr
*/

#include <stddef.h>

void my_putstr(char *str);
void my_putchar(char c);

void my_putarr(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        my_putstr(array[i]);
}
