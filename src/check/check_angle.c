/*
** EPITECH PROJECT, 2022
** check_angle.c
** File description:
** check_angle
*/

#include "my.h"
#include "proto.h"

block_t *check_angle_right(map_t *map, int tmp)
{
    if (is_right(*map, tmp) == 1 && map->state == RIGHT) {
        map->state = RIGHT;
        return return_horizontal(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_up(*map, tmp) == 1 && map->state == RIGHT) {
        map->state = UP;
        return return_bot_right(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_down(*map, tmp) == 1 && map->state == RIGHT) {
        map->state = DOWN;
        return return_top_right(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    return NULL;
}

block_t *check_angle_left(map_t *map, int tmp)
{
    if (is_left(*map, tmp) == 1 && map->state == LEFT) {
        map->state = LEFT;
        return return_horizontal(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_up(*map, tmp) == 1 && map->state == LEFT) {
        map->state = UP;
        return return_bot_left(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_down(*map, tmp) == 1 && map->state == LEFT) {
        map->state = DOWN;
        return return_top_left(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    return NULL;
}

block_t *check_angle_up(map_t *map, int tmp)
{
    if (is_up(*map, tmp) == 1 && map->state == UP) {
        map->state = UP;
        return return_vertical(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_right(*map, tmp) == 1 && map->state == UP) {
        map->state = RIGHT;
        return return_top_left(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_left(*map, tmp) == 1 && map->state == UP) {
        map->state = LEFT;
        return return_top_right(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    return NULL;
}

block_t *check_angle_down(map_t *map, int tmp)
{
    if (is_down(*map, tmp) == 1 && map->state == DOWN) {
        map->state = DOWN;
        return return_vertical(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_right(*map, tmp) == 1 && map->state == DOWN) {
        map->state = RIGHT;
        return return_bot_left(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    if (is_left(*map, tmp) == 1 && map->state == DOWN) {
        map->state = LEFT;
        return return_bot_right(map->mob_path_x[tmp] * SIZE,
        map->mob_path_y[tmp] * SIZE, map->sheet);
    }
    return NULL;
}
