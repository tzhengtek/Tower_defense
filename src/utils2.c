/*
** EPITECH PROJECT, 2022
** utils2.c
** File description:
** utils2
*/

#include "proto.h"

int condition_nb_pos(char c1, int count, char c2)
{
    if (c1 == c2)
        count++;
    return count;
}

int return_nb_pos(char **map, char c)
{
    int count = 0;

    for (int i = 3; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            count = condition_nb_pos(map[i][j], count, c);
    }
    return count;
}

sfVector2f copy_vector(sfVector2f pos)
{
    sfVector2f pos1;

    pos1.x = pos.x;
    pos1.y = pos.y;
    return pos1;
}

int my_vectcmp(sfVector2f pos1, sfVector2f pos2)
{
    if (pos1.x == pos2.x && pos1.y == pos2.y)
        return 1;
    return 0;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
