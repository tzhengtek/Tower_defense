/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** task06
*/

void my_putchar(char c);

int my_strcmp(char const *s1, char const *s2);

int my_strlen(char const *c);

int my_strcmp(char const *s1, char const *s2)
{
    int a = my_strlen(s2) + 1;

    if (my_strlen(s1) < my_strlen(s2))
        a = my_strlen(s1) + 1;
    for (int i = 0; i < a; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
