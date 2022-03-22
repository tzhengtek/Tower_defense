/*
** EPITECH PROJECT, 2022
** display_rotate_mob.c
** File description:
** display_rotate_mob
*/

#include "proto.h"

void rotate_sprite_right
(mob_t *mob, block_t *path, game_type_t type, direction_t direction)
{
    if (path->type == type && mob->direction == direction) {
        if (my_vectcmp(mob->position, path->position) == 1) {
            sfTexture_destroy
            ((sfTexture *)(sfSprite_getTexture(mob->mob_sprite)));
            sfSprite_destroy(mob->mob_sprite);
            mob->mob_sprite = create_sprite("sprite/enemy_right.png");
            sfSprite_setScale(mob->mob_sprite, (sfVector2f) {1.725, 1.725});
            mob->direction = right;
        }
    }
}

void rotate_sprite_down
(mob_t *mob, block_t *path, game_type_t type, direction_t direction)
{
    if (path->type == type && mob->direction == direction) {
        if (my_vectcmp(mob->position, path->position) == 1) {
            sfTexture_destroy
            ((sfTexture *)(sfSprite_getTexture(mob->mob_sprite)));
            sfSprite_destroy(mob->mob_sprite);
            mob->mob_sprite = create_sprite("sprite/enemy_down.png");
            sfSprite_setScale(mob->mob_sprite, (sfVector2f) {1.725, 1.725});
            mob->direction = down;
        }
    }
}

void rotate_sprite_left
(mob_t *mob, block_t *path, game_type_t type, direction_t direction)
{
    if (path->type == type && mob->direction == direction) {
        if (my_vectcmp(mob->position, path->position) == 1) {
            sfTexture_destroy
            ((sfTexture *)(sfSprite_getTexture(mob->mob_sprite)));
            sfSprite_destroy(mob->mob_sprite);
            mob->mob_sprite = create_sprite("sprite/enemy_left.png");
            sfSprite_setScale(mob->mob_sprite, (sfVector2f) {1.725, 1.725});
            mob->direction = left;
        }
    }
}

void rotate_sprite_up
(mob_t *mob, block_t *path, game_type_t type, direction_t direction)
{
    if (path->type == type && mob->direction == direction) {
        if (my_vectcmp(mob->position, path->position) == 1) {
            sfTexture_destroy
            ((sfTexture *)(sfSprite_getTexture(mob->mob_sprite)));
            sfSprite_destroy(mob->mob_sprite);
            mob->mob_sprite = create_sprite("sprite/enemy_up.png");
            sfSprite_setScale(mob->mob_sprite, (sfVector2f) {1.725, 1.725});
            mob->direction = up;
        }
    }
}

void display_rotate_mob(block_t **path, mob_t **mob)
{
    for (int i = 0; mob[i]->type != null; i++) {
        for (int j = 0; path[j]->type != null; j++) {
            rotate_sprite_right(mob[i], path[j], top_left, up);
            rotate_sprite_down(mob[i], path[j], top_left, left);
            rotate_sprite_right(mob[i], path[j], bot_left, down);
            rotate_sprite_up(mob[i], path[j], bot_left, left);
            rotate_sprite_down(mob[i], path[j], top_right, right);
            rotate_sprite_left(mob[i], path[j], top_right, up);
            rotate_sprite_up(mob[i], path[j], bot_right, right);
            rotate_sprite_left(mob[i], path[j], bot_right, down);
        }
    }
}
