/*
** EPITECH PROJECT, 2022
** attack_tower.c
** File description:
** attack_tower
*/

#include "scene.h"

void tower_focus_attack
(tower_t *tower, mob_t *mob, game_t *game, win_t *window)
{
    if (tower->tower_type == normal && window->dt.count > 0.8) {
        mob_state(mob, game, 1);
        window->dt.count = 0;
    }
    if (tower->tower_type == sniper && window->dt.count2 > 5.0) {
        mob_state(mob, game, 5);
        window->dt.count2 = 0;
    }
}

void zone_attack_tower(tower_t *tower, mob_t *mob, game_t *game)
{
    if (tower->tower_type == slower) {
        if (tower_shot(tower, mob) == 1)
            mob->speed = mob->speed_save / 1.2;
        else
            mob->speed = mob->speed_save;
    }
    if (tower->tower_type == laser) {
        if (tower_shot(tower, mob) == 1)
            mob_state(mob, game, 0.005);
    }
}

void attack_time(mob_t *mob, tower_t *tower, game_t *game, win_t *window)
{
    zone_attack_tower(tower, mob, game);
    cast_tower_focus(mob, tower);
    if (mob->id == tower->focus)
        tower_focus_attack(tower, mob, game, window);
}

void tower_attack(mob_t *mob, game_t *game, win_t *window)
{
    for (int j = 0; game->tower[j]->type != null; j++) {
        if (game->tower[j]->tower_type != none)
            attack_time(mob, game->tower[j], game, window);
    }
}

void check_tower_attack(game_t *game, win_t *window)
{
    for (int i = 0; game->mob[i]->type != null; i++)
        tower_attack(game->mob[i], game, window);
    for (int i = 0; game->tower[i]->type != null; i++) {
        if (game->tower[i]->tower_type != none) {
            sfRenderWindow_drawSprite
            (window->window, game->tower[i]->tower, NULL);
            sfRenderWindow_drawCircleShape
            (window->window, game->tower[i]->circle, NULL);
        }
    }
}
