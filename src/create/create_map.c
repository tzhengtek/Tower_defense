/*
** EPITECH PROJECT, 2022
** create_map.c
** File description:
** create_map
*/

#include "scene.h"

tower_t *create_tower(int x, int y, sfSprite *sheet)
{
    tower_t *tower = malloc(sizeof(tower_t));
    sfIntRect rectangle = create_rect(0, 8000, 1000, 1000);

    if (tower == NULL)
        return NULL;
    sfSprite_setTextureRect(sheet, rectangle);
    tower->block_sprite = sfSprite_copy(sheet);
    sfSprite_setScale(tower->block_sprite, (sfVector2f) {0.06, 0.06});
    tower->position =
    create_vector((float)(y * SIZE), (float)(x * SIZE));
    tower->type = tower_type;
    tower->tower_type = none;
    tower->hitbox = sfSprite_getGlobalBounds(tower->block_sprite);
    tower->radius = 0;
    tower->focus = -1;
    return tower;
}

int condition_create_map
(tower_t **tower, coord_t position, int tmp, map_t *map)
{
    if (map->map[position.x][position.y] == '3') {
        tower[tmp] = create_tower(position.x, position.y, map->sheet);
        tmp++;
    }
    return tmp;
}

tower_t **create_map(map_t *map)
{
    int count = return_nb_pos(map->map, '3');
    tower_t **tower;
    int tmp = 0;
    coord_t pos;

    tower = malloc(sizeof(tower_t) * (count + 1));
    if (tower == NULL)
        return NULL;
    for (pos.x = 0; map->map[pos.x] != NULL; pos.x++) {
        for (pos.y = 0; map->map[pos.x][pos.y] != '\0'; pos.y++)
            tmp = condition_create_map(tower, pos, tmp, map);
    }
    tower[tmp] = create_tower(-1, 0, map->sheet);
    tower[tmp]->type = null;
    map->nb_tower = tmp;
    return tower;
}
