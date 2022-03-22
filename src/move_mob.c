/*
** EPITECH PROJECT, 2022
** move_mob.c
** File description:
** move_mob
*/

#include "proto.h"

int move_position_x(mob_t *mob, win_t *window, map_t map)
{
    float mob_x = mob->position.x;
    float point_x = mob->checkpoint->point_pos[mob->checkpoint->tmp].x;
    float old_point_x = mob->checkpoint->point_pos[mob->checkpoint->tmp - 1].x;
    float length_mob = fabs(mob_x - old_point_x);
    float length_point = fabs(point_x - old_point_x);

    if (mob_x != point_x && mob->life_state != dead) {
        if (mob_x < point_x)
            mob->position.x += mob->speed * window->dt.time;
        else if (mob_x > point_x)
            mob->position.x -= mob->speed * window->dt.time;
        if (length_mob >= length_point && mob_x > map.start.x *
        SIZE && mob_x < map.end.x * SIZE) {
            mob->position =
            copy_vector(mob->checkpoint->point_pos[mob->checkpoint->tmp]);
            mob->checkpoint->tmp++;
        }
        return 1;
    }
    return 0;
}

void move_position_y(mob_t *mob, win_t *window)
{
    float mob_y = mob->position.y;
    float point_y = mob->checkpoint->point_pos[mob->checkpoint->tmp].y;
    float old_point_y = mob->checkpoint->point_pos[mob->checkpoint->tmp - 1].y;
    float length_mob = fabs(mob_y - old_point_y);
    float length_point = fabs(point_y - old_point_y);

    if (mob_y != point_y && mob->life_state != dead) {
        if (mob_y < point_y)
            mob->position.y += mob->speed * window->dt.time;
        else if (mob_y > point_y)
            mob->position.y -= mob->speed * window->dt.time;
        if (length_mob >= length_point) {
            mob->position =
            copy_vector(mob->checkpoint->point_pos[mob->checkpoint->tmp]);
            mob->checkpoint->tmp++;
        }
    }
}

void move_mob(mob_t **mob, win_t *window, map_t map)
{
    for (int i = 0; mob[i]->type != null; i++) {
        if (mob[i]->position.x >= map.end.x * SIZE) {
            mob[i]->position.x = -1 * SIZE;
            mob[i]->position.y = -1 * SIZE;
            mob[i]->life_state = dead;
            window->base_life--;
        }
        if (move_position_x(mob[i], window, map) == 0)
            move_position_y(mob[i], window);
        sfRectangleShape_setPosition(mob[i]->red,
        (sfVector2f){mob[i]->position.x, mob[i]->position.y - 10});
        sfRectangleShape_setSize(mob[i]->green,
        (sfVector2f){mob[i]->life * 11 , 5});
        sfRectangleShape_setPosition(mob[i]->green,
        (sfVector2f){mob[i]->position.x, mob[i]->position.y - 10});
    }
}
