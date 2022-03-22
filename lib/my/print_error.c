/*
** EPITECH PROJECT, 2022
** print_error.c
** File description:
** print_error
*/

#include <unistd.h>

int my_strlen(char *str);

void print_error(char *str)
{
    write(2, str, my_strlen(str));
}
