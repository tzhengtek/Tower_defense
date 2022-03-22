/*
** EPITECH PROJECT, 2022
** create_path_sprite.c
** File description:
** create_path_sprite
*/

#include "my.h"
#include "proto.h"

block_t *return_path(map_t *map, int tmp)
{
    block_t *block;

    if ((block = check_angle_right(map, tmp)) != NULL)
        return block;
    if ((block = check_angle_left(map, tmp)) != NULL)
        return block;
    if ((block = check_angle_up(map, tmp)) != NULL)
        return block;
    if ((block = check_angle_down(map, tmp)) != NULL)
        return block;
    return block;
}

block_t *return_last_sprite(map_t *map)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(2000, 8000, 1000, 1000);

    sfSprite_setTextureRect(map->sheet, rectangle);
    block->block_sprite = sfSprite_copy(map->sheet);
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.06, 0.06});
    block->position.x = map->end.x * SIZE;
    block->position.y = map->end.y * SIZE;
    block->type = block_type;
    return block;
}

block_t *return_spawn_sprite(map_t *map)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(1000, 8000, 1000, 1000);

    sfSprite_setTextureRect(map->sheet, rectangle);
    block->block_sprite = sfSprite_copy(map->sheet);
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.06, 0.06});
    block->position.x = map->start.x * SIZE;
    block->position.y = map->start.y * SIZE;
    block->type = block_type;
    return block;
}

block_t **create_path(map_t map)
{
    block_t **mob_path = malloc(sizeof(block_t) * (map.count + 2));

    if (mob_path == NULL)
        return NULL;
    map.state = RIGHT;
    for (int tmp = 0; tmp < map.count; tmp++) {
        mob_path[tmp] = return_path(&map, tmp);
        mob_path[tmp]->count = map.count;
    }
    mob_path[map.count] = return_last_sprite(&map);
    mob_path[map.count + 1] = return_spawn_sprite(&map);
    mob_path[map.count + 2] = return_spawn_sprite(&map);
    mob_path[map.count + 2]->type = null;
    return mob_path;
}
