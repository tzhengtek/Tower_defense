/*
** EPITECH PROJECT, 2022
** tower_attack2.c
** File description:
** tower_attack2
*/

#include "scene.h"

void cast_tower_focus(mob_t *mob, tower_t *tower)
{
    if ((tower_shot(tower, mob) == 0 || mob->life_state == dead) &&
    tower->focus == mob->id)
        tower->focus = -1;
    if (tower_shot(tower, mob) == 1) {
        if (mob->id > tower->focus)
            tower->focus = mob->id;
    }
}

void mob_state(mob_t *mob, game_t *game, float damage)
{
    if (mob->life_state != dead) {
        mob->life -= damage;
        if (mob->life <= 0 && mob->life_state != dead) {
            mob->position = create_vector(-1 * SIZE, -1 * SIZE);
            mob->life_state = dead;
            game->money += 40;
            game->nb_mob--;
            game->score += 50;
        }
    }
}

int tower_shot(tower_t *tower, mob_t *mob)
{
    float testx = tower->circle_center.x;
    float testy = tower->circle_center.y;
    float distx = 0;
    float disty = 0;
    float distance = 0;

    if (tower->circle_center.x < mob->position.x)
        testx = mob->position.x;
    else if (tower->circle_center.x > mob->position.x + SIZE)
        testx = mob->position.x + SIZE;
    if (tower->circle_center.y < mob->position.y)
        testy = mob->position.y;
    else if (tower->circle_center.y > mob->position.y + SIZE)
        testy = mob->position.y + SIZE;
    distx = tower->circle_center.x - testx;
    disty = tower->circle_center.y - testy;
    distance = sqrt(powf(distx, 2) + powf(disty, 2));
    if (distance <= tower->radius)
        return 1;
    return 0;
}
