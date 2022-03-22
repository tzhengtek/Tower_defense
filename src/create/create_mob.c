/*
** EPITECH PROJECT, 2022
** create_mob.c
** File description:
** craete_mob
*/

#include "proto.h"
#include "my.h"

sfRectangleShape *create_hp(sfVector2f pos, sfColor color)
{
    sfRectangleShape *rec = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rec, color);
    sfRectangleShape_setSize(rec, (sfVector2f){55, 5});
    sfRectangleShape_setPosition(rec, (sfVector2f){pos.x, pos.y - 10});
    return rec;
}

mob_t *create_mob(map_t map, block_t **path, int value)
{
    mob_t *mob = malloc(sizeof(mob_t));

    if (mob == NULL)
        return NULL;
    mob->count = map.count;
    mob->mob_sprite = create_sprite("sprite/enemy_right.png");
    mob->position = create_vector
    ((map.start.x - (1.5 * value)) * SIZE, map.start.y * SIZE);
    sfSprite_setScale(mob->mob_sprite, (sfVector2f) {1.725, 1.725});
    mob->checkpoint = create_all_checkpoint(path, map);
    mob->red = create_hp(mob->position, sfRed);
    mob->green = create_hp(mob->position, sfGreen);
    mob->type = mob_type;
    mob->direction = right;
    mob->id = map.nb_mob - value;
    mob->life = 5;
    mob->speed = 1;
    mob->speed_save = mob->speed;
    mob->life_state = alive;
    return mob;
}

mob_t **create_all_mob(map_t map, block_t **path)
{
    mob_t **all_mob = malloc(sizeof(mob_t) * (map.nb_mob + 1));
    int i = 0;

    if (all_mob == NULL)
        return NULL;
    for (; i < map.nb_mob; i++)
        all_mob[i] = create_mob(map, path, i);
    all_mob[i] = create_mob(map, path, i);
    all_mob[i]->type = null;
    return all_mob;
}
