/*
** EPITECH PROJECT, 2022
** checy_path.c
** File description:
** checy_path
*/

#include "proto.h"
#include "my.h"

int condition_connected(char **map, coord_t *path, int x, int y)
{
    if (x > LINE - 1 || x < 3 || y < 0 || y > COLUMN - 1)
        return 0;
    if (map[x][y] == ' ' || map[x][y] == '1') {
        map[path->x][path->y] = '-';
        path->y = y;
        path->x = x;
        return 1;
    }
    return 0;
}

int is_linyed(char **map, coord_t *path)
{
    if (condition_connected(map, path, path->x, path->y + 1) == 1)
        return 1;
    if (condition_connected(map, path, path->x - 1, path->y) == 1)
        return 1;
    if (condition_connected(map, path, path->x, path->y - 1) == 1)
        return 1;
    if (condition_connected(map, path, path->x + 1, path->y) == 1)
        return 1;
    return 0;
}

int is_connected(char **map, coord_t *path)
{
    int count = 0;

    count = is_linyed(map, path);
    if (count == 0)
        return 84;
    return 0;
}

int is_path(coord_t *path, char **map)
{
    for (; map[path->x][path->y] != '1';) {
        if (is_connected(map, path) == 84)
            return 84;
    }
    return 0;
}

int check_path(char **map)
{
    coord_t path;

    for (int i = 0; map[i] != NULL; i++) {
        if (map[i][0] == '0') {
            path.x = i;
            path.y = 1;
        }
    }
    if (is_path(&path, map) == 84)
        return 84;
    return 0;
}
