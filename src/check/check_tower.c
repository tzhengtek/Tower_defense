/*
** EPITECH PROJECT, 2022
** check_tower.c
** File description:
** check_tower
*/

#include "scene.h"

void check_put_tower2(map_t map, win_t *window, tower_t *tower, game_t *game)
{
    if (window->mouse.type == slower && game->money >= 280) {
        put_tower_slower(map, tower, game->sfx.place);
        window->mouse.type = none;
        game->money -= 280;
    }
    if (window->mouse.type == sniper && game->money >= 550) {
        put_tower_sniper(map, tower, game->sfx.place);
        window->mouse.type = none;
        game->money -= 550;
    }
}

void check_put_tower(map_t map, win_t *window, tower_t *tower, game_t *game)
{
    if (tower->tower_type == none) {
        if (window->mouse.type == normal && game->money >= 60) {
            put_tower_normal(map, tower, game->sfx.place);
            window->mouse.type = none;
            game->money -= 60;
        }
        if (window->mouse.type == laser && game->money >= 200) {
            put_tower_laser(map, tower, game->sfx.place);
            window->mouse.type = none;
            game->money -= 200;
        }
        check_put_tower2(map, window, tower, game);
    }
}

void check_pose_tower(win_t *window, game_t *game, map_t map)
{
    for (int i = 0; game->tower[i]->type != null; i++) {
        window->mouse.position =
        sfMouse_getPosition((const sfWindow *)window->window);
        if (window->event.mouseButton.button == sfMouseLeft &&
        check_inside_rect
        (game->tower[i]->position, window->mouse.position, SIZE) == 1)
            check_put_tower(map, window, game->tower[i], game);
    }
}
