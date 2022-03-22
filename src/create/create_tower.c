/*
** EPITECH PROJECT, 2022
** create_tower.c
** File description:
** create_tower
*/

#include "proto.h"
#include "my.h"

void condition_fill_map(char **map, int i, int j)
{
    if (map[i][j] == ' ' || map[i][j] == '3')
        map[i][j] = '#';
}

void fill_map(char **map)
{
    for (int i = 3; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            condition_fill_map(map, i, j);
    }
}

void pose_tower(char **map, int x, int y)
{
    if (x - 1 >= 0 && map[x - 1][y] == '#')
        map[x - 1][y] = '3';
    if (x - 2 >= 0 && map[x - 2][y] == '#')
        map[x - 2][y] = '3';
    if (x  + 1 < LINE && map[x + 1][y] == '#')
        map[x + 1][y] = '3';
    if (x + 2 < LINE && map[x + 2][y] == '#')
        map[x + 2][y] = '3';
    if (y - 1 >= 0 && map[x][y - 1] == '#')
        map[x][y - 1] = '3';
    if (y - 2 >= 0 && map[x][y - 2] == '#')
        map[x][y - 2] = '3';
    if (y + 1 < COLUMN && map[x][y + 1] == '#')
        map[x][y + 1] = '3';
    if (y + 2 < COLUMN && map[x][y + 2] == '#')
        map[x][y + 2] = '3';
}

void place_tower(map_t *map)
{
    for (int i = 0; i < map->count; i++)
        pose_tower(map->map, (int)map->mob_path_y[i], (int)map->mob_path_x[i]);
}
