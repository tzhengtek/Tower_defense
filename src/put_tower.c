/*
** EPITECH PROJECT, 2022
** put_tower.c
** File description:
** put_tower
*/

#include "scene.h"

void put_tower_normal(map_t map, tower_t *tower, sfSound *place)
{
    sfIntRect rectangle = create_rect(0, 4000, 1000, 1000);

    sfSprite_setTextureRect(map.sheet, rectangle);
    tower->tower = sfSprite_copy(map.sheet);
    sfSprite_setScale(tower->tower, (sfVector2f){0.06, 0.06});
    tower->circle = sfCircleShape_create();
    tower->tower_type = normal;
    tower->radius = 140;
    sfCircleShape_setRadius(tower->circle, tower->radius);
    tower->circle_center = create_vector(tower->position.x +
    (SIZE / 2), tower->position.y + (SIZE / 2));
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 35});
    tower->circle_pos = create_vector((tower->position.x + (SIZE / 2))
    - tower->radius, (tower->position.y + (SIZE / 2)) - tower->radius);
    sfSprite_setPosition(tower->tower, tower->position);
    sfCircleShape_setPosition(tower->circle, tower->circle_pos);
    sfSound_play(place);
}

void put_tower_laser(map_t map, tower_t *tower, sfSound *place)
{
    sfIntRect rectangle = create_rect(0, 3000, 1000, 1000);

    sfSprite_setTextureRect(map.sheet, rectangle);
    tower->tower = sfSprite_copy(map.sheet);
    sfSprite_setScale(tower->tower, (sfVector2f){0.06, 0.06});
    tower->circle = sfCircleShape_create();
    tower->tower_type = laser;
    tower->radius = 130;
    sfCircleShape_setRadius(tower->circle, tower->radius);
    tower->circle_center = create_vector(tower->position.x +
    (SIZE / 2), tower->position.y + (SIZE / 2));
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 35});
    tower->circle_pos = create_vector((tower->position.x + (SIZE / 2))
    - tower->radius, (tower->position.y + (SIZE / 2)) - tower->radius);
    sfSprite_setPosition(tower->tower, tower->position);
    sfCircleShape_setPosition(tower->circle, tower->circle_pos);
    sfSound_play(place);
}

void put_tower_slower(map_t map, tower_t *tower, sfSound *place)
{
    sfIntRect rectangle = create_rect(0, 6000, 1000, 1000);

    sfSprite_setTextureRect(map.sheet, rectangle);
    tower->tower = sfSprite_copy(map.sheet);
    sfSprite_setScale(tower->tower, (sfVector2f){0.06, 0.06});
    tower->circle = sfCircleShape_create();
    tower->tower_type = slower;
    tower->radius = 120;
    sfCircleShape_setRadius(tower->circle, tower->radius);
    tower->circle_center = create_vector(tower->position.x +
    (SIZE / 2), tower->position.y + (SIZE / 2));
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 35});
    tower->circle_pos = create_vector((tower->position.x + (SIZE / 2))
    - tower->radius, (tower->position.y + (SIZE / 2)) - tower->radius);
    sfSprite_setPosition(tower->tower, tower->position);
    sfCircleShape_setPosition(tower->circle, tower->circle_pos);
    sfSound_play(place);
}

void put_tower_sniper(map_t map, tower_t *tower, sfSound *place)
{
    sfIntRect rectangle = create_rect(1000, 3000, 1000, 1000);

    sfSprite_setTextureRect(map.sheet, rectangle);
    tower->tower = sfSprite_copy(map.sheet);
    sfSprite_setScale(tower->tower, (sfVector2f){0.06, 0.06});
    tower->circle = sfCircleShape_create();
    tower->tower_type = sniper;
    tower->radius = 300;
    sfCircleShape_setRadius(tower->circle, tower->radius);
    tower->circle_center = create_vector(tower->position.x +
    (SIZE / 2), tower->position.y + (SIZE / 2));
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 35});
    tower->circle_pos = create_vector((tower->position.x + (SIZE / 2))
    - tower->radius, (tower->position.y + (SIZE / 2)) - tower->radius);
    sfSprite_setPosition(tower->tower, tower->position);
    sfCircleShape_setPosition(tower->circle, tower->circle_pos);
    sfSound_play(place);
}
