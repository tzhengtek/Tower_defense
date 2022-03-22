/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** destroy
*/

#include "my.h"
#include "scene.h"

void destroy_all_mob(block_t **mob_path, int value)
{
    int i = 0;

    for (; i < value; i++) {
        sfSprite_destroy(mob_path[i]->block_sprite);
        free(mob_path[i]);
    }
    sfSprite_destroy(mob_path[i]->block_sprite);
    free(mob_path[i]);
    free(mob_path);
}

void destroy_mob(mob_t **mob, int value)
{
    for (int i = 0; i <= value; i++) {
        sfTexture_destroy
        ((sfTexture *)sfSprite_getTexture(mob[i]->mob_sprite));
        sfSprite_destroy(mob[i]->mob_sprite);
        sfRectangleShape_destroy(mob[i]->red);
        sfRectangleShape_destroy(mob[i]->green);
        free(mob[i]->checkpoint->point_pos);
        free(mob[i]->checkpoint);
        free(mob[i]);
    }
    free(mob);
}
