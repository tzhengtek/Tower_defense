/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Oya oya
*/

void my_putchar(char c);

void my_putstr(const char *str);

void my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
}
