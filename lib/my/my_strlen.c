/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** Oya ara
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_strlen(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        i++;
        nb++;
    }
    return (nb);
    my_putchar('\n');
}
