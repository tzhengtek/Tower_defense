/*
** EPITECH PROJECT, 2022
** check_next_pos.c
** File description:
** check_next_pos
*/

#include "my.h"
#include "proto.h"

int is_right(map_t map, int tmp)
{
    int cond1 = (map.mob_path_y[tmp] == map.mob_path_y[tmp + 1]);
    int cond2 = (map.mob_path_x[tmp] < map.mob_path_x[tmp + 1]);

    if (cond1 && cond2)
        return 1;
    return 0;
}

int is_left(map_t map, int tmp)
{
    int cond1 = (map.mob_path_y[tmp] == map.mob_path_y[tmp + 1]);
    int cond2 = (map.mob_path_x[tmp] > map.mob_path_x[tmp + 1]);

    if (cond1 && cond2)
        return 1;
    return 0;
}

int is_up(map_t map, int tmp)
{
    int cond1 = (map.mob_path_x[tmp] == map.mob_path_x[tmp + 1]);
    int cond2 = (map.mob_path_y[tmp] > map.mob_path_y[tmp + 1]);

    if (cond1 && cond2)
        return 1;
    return 0;
}

int is_down(map_t map, int tmp)
{
    int cond1 = (map.mob_path_x[tmp] == map.mob_path_x[tmp + 1]);
    int cond2 = (map.mob_path_y[tmp] < map.mob_path_y[tmp + 1]);

    if (cond1 && cond2)
        return 1;
    return 0;
}
