/*
** EPITECH PROJECT, 2022
** check_map.c
** File description:
** check_map
*/

#include "proto.h"

int check_spawn(map_t *map)
{
    int count = 0;
    int save = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        if (map->map[i][0] == '0') {
            save = i;
            count++;
        }
    }
    if (count != 1)
        return 84;
    map->start = create_vector((float)(0), (float)save);
    return 1;
}

int check_castle(map_t *map)
{
    int count = 0;
    int index = column_size(map->map);
    int i = 0;
    int save = 0;

    for (; map->map[i] != NULL; i++) {
        if (map->map[i][index - 1] == '1') {
            save = i;
            count++;
        }
    }
    if (count != 1)
        return 84;
    map->end = create_vector((float)(index - 1), (float)save);
    return 1;
}

int good_map_condition(char c)
{
    char element[6] = "01 #3";

    for (int i = 0; element[i] != '\0'; i++) {
        if (c == element[i])
            return 0;
    }
    return 1;
}

int correct_map(char **map)
{
    int error = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            error += good_map_condition(map[i][j]);
    }
    if (error != 0)
        return 84;
    return 1;
}
