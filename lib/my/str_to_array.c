/*
** EPITECH PROJECT, 2022
** str_to_array.c
** File description:
** str_to_array
*/

#include <stdlib.h>
#include <stddef.h>

void create_array(char **array, char *str, char c, char t)
{
    int x = 0;
    int y = 0;

    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] != c && str[i] != t) &&
        ((str[i + 1] != c || str[i + 1] != t) || str[i + 1] != '\0')) {
            array[x][y] = str[i];
            y++;
        }
        if ((str[i] != c && str[i] != t) &&
        ((str[i + 1] == c || str[i + 1] == t) || str[i + 1] == '\0')) {
            array[x][y] = '\0';
            x++;
            y = 0;
        }
    }
    array[x] = NULL;
}

int count_str(char *str, char c, char t)
{
    int count = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] != c && str[i] != t &&
        (str[i + 1] == c || str[i + 1] == t || str[i + 1] == '\0'))
            count++;
    }
    return count;
}

char **str_to_array(char *str, char c, char t)
{
    int count = count_str(str, c, t);
    int size = 0;
    int j = 0;
    char **array = malloc(sizeof(char *) * (count + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != c && str[i] != t) &&
        ((str[i + 1] != c || str[i + 1] != t) || str[i + 1] != '\0'))
            size++;
        if ((str[i] != c && str[i] != t) &&
        ((str[i + 1] == c || str[i + 1] == t) || str[i + 1] == '\0')) {
            array[j] = malloc(sizeof(char) * (size + 1));
            j++;
            size = 0;
        }
    }
    create_array(array, str, c, t);
    return array;
}
