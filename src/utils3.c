/*
** EPITECH PROJECT, 2022
** utils3.c
** File description:
** utils3
*/

#include "proto.h"

void init_time(delta_t *dt)
{
    dt->clock = sfClock_create();
    dt->old.microseconds = 0;
    dt->count = 0;
    dt->count2 = 0;
}

void update_time(delta_t *dt)
{
    dt->cur = sfClock_getElapsedTime(dt->clock);
    dt->time =
    ((dt->cur.microseconds - dt->old.microseconds) / 10000.0);
    dt->old = dt->cur;
    dt->count += dt->time / 100;
    dt->count2 += dt->time / 100;
}

sfVector2f copy_vector_size(sfVector2f pos)
{
    sfVector2f new_pos;

    new_pos.x = pos.x * SIZE;
    new_pos.y = pos.y * SIZE;
    return new_pos;
}

sfIntRect *rect_move(sfIntRect *rectangle, int left, int max)
{
    if (rectangle->left < max)
        rectangle->left += left;
    else
        rectangle->left = 0;
    return rectangle;
}
