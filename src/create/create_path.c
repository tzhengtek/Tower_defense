/*
** EPITECH PROJECT, 2022
** path_info.c
** File description:
** path_info
*/

#include "my.h"
#include "proto.h"

int is_a_path(map_t *map, int y, int x, coord_t *path)
{
    if (y > LINE - 1 || y < 3 || x < 0 || x > COLUMN - 1)
        return 0;
    if (map->map[y][x] == '-' || map->map[y][x] == '1') {
        map->map[path->y][path->x] = ' ';
        map->mob_path_x[map->tmp] = (float)x;
        map->mob_path_y[map->tmp] = (float)y;
        map->tmp++;
        path->x = x;
        path->y = y;
        return 1;
    }
    return 0;
}

int check_path_pos(map_t *map, coord_t *path)
{
    if (is_a_path(map, path->y, path->x + 1, path) == 1)
        return 1;
    if (is_a_path(map, path->y - 1, path->x, path) == 1)
        return 1;
    if (is_a_path(map, path->y, path->x - 1, path) == 1)
        return 1;
    if (is_a_path(map, path->y + 1, path->x, path) == 1)
        return 1;
    return 0;
}

void return_mob_path(map_t *map)
{
    map->count = return_nb_pos(map->map, '-');
    map->mob_path_x = malloc(sizeof(float) * (map->count + 1));
    map->mob_path_y = malloc(sizeof(float) * (map->count + 1));
    map->tmp = 0;
}

void create_mob_path(map_t *map)
{
    coord_t path;

    map->sheet = create_sprite("sprite/sp_test.png");
    return_mob_path(map);
    for (int i = 0; map->map[i] != NULL; i++) {
        if (map->map[i][0] == '0') {
            path.y = i;
            path.x = 1;
            map->mob_path_x[map->tmp] = (float)path.x;
            map->mob_path_y[map->tmp] = (float)path.y;
            map->tmp++;
        }
    }
    fill_map(map->map);
    for (int i = 1; i < map->count + 1; i++)
        check_path_pos(map, &path);
    map->nb_mob = (rand() % ((map->count / 2) - 5 + 1) + 5);
    place_tower(map);
}
