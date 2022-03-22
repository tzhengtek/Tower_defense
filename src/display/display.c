/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/

#include "scene.h"

void display_all_mob(win_t *window, mob_t **mob, block_t **path, map_t map)
{
    if (window->state != in_menu && window->state != is_paused)
        move_mob(mob, window, map);
    display_rotate_mob(path, mob);
    for (int i = 0; mob[i]->type != null; i++) {
        if (mob[i]->position.x > map.start.x * SIZE && mob[i]->life > 0) {
            sfSprite_setPosition(mob[i]->mob_sprite, mob[i]->position);
            sfRenderWindow_drawSprite
            (window->window, mob[i]->mob_sprite, NULL);
            sfRenderWindow_drawRectangleShape
            (window->window, mob[i]->red, NULL);
            sfRenderWindow_drawRectangleShape
            (window->window, mob[i]->green, NULL);
        }
    }
}

void display_window
(win_t window, tower_t **tower, sfSprite *bg, block_t **path)
{
    sfRenderWindow_drawSprite(window.window, bg, NULL);
    for (int i = 0; tower[i]->type != null; i++) {
        sfSprite_setPosition
        (tower[i]->block_sprite, tower[i]->position);
        sfRenderWindow_drawSprite
        (window.window, tower[i]->block_sprite, NULL);
    }
    for (int i = 0; path[i]->type != null; i++) {
        sfSprite_setPosition(path[i]->block_sprite, path[i]->position);
        sfRenderWindow_drawSprite(window.window, path[i]->block_sprite, NULL);
    }
}
