/*
** EPITECH PROJECT, 2022
** create_sprite_linear.c
** File description:
** create_sprite_linear
*/

#include "my.h"
#include "proto.h"

block_t *return_horizontal(float x, float y, sfSprite *sheet)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(0, 2000, 1000, 1000);

    block->type = block_type;
    block->position.x = x;
    block->position.y = y;
    sfSprite_setTextureRect(sheet, rectangle);
    block->block_sprite = sfSprite_copy(sheet);
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.06, 0.06});
    block->type = horizontal;
    return block;
}

block_t *return_vertical(float x, float y, sfSprite *sheet)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(1000, 2000, 1000, 1000);

    block->type = block_type;
    block->position.x = x;
    block->position.y = y;
    sfSprite_setTextureRect(sheet, rectangle);
    block->block_sprite = sfSprite_copy(sheet);
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.06, 0.06});
    block->type = vertical;
    return block;
}
