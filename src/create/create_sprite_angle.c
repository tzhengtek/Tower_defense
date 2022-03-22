/*
** EPITECH PROJECT, 2022
** create_sprite_angle.c
** File description:
** create_sprite_angle
*/

#include "my.h"
#include "proto.h"

block_t *return_bot_left(float x, float y, sfSprite *sheet)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(1000, 0, 1000, 1000);

    block->type = block_type;
    block->position.x = x;
    block->position.y = y;
    sfSprite_setTextureRect(sheet, rectangle);
    block->block_sprite = sfSprite_copy(sheet);
    block->type = bot_left;
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.06, 0.0596});
    return block;
}

block_t *return_bot_right(float x, float y, sfSprite *sheet)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(1000, 1000, 1000, 1000);

    block->type = block_type;
    block->position.x = x;
    block->position.y = y;
    sfSprite_setTextureRect(sheet, rectangle);
    block->block_sprite = sfSprite_copy(sheet);
    block->type = bot_right;
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.0596, 0.0596});
    return block;
}

block_t *return_top_left(float x, float y, sfSprite *sheet)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(0, 0, 1000, 1000);

    block->type = block_type;
    block->position.x = x;
    block->position.y = y;
    sfSprite_setTextureRect(sheet, rectangle);
    block->block_sprite = sfSprite_copy(sheet);
    block->type = top_left;
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.0596, 0.0596});
    return block;
}

block_t *return_top_right(float x, float y, sfSprite *sheet)
{
    block_t *block = malloc(sizeof(block_t));
    sfIntRect rectangle = create_rect(0, 1000, 1000, 1000);

    block->type = block_type;
    block->position.x = x;
    block->position.y = y;
    sfSprite_setTextureRect(sheet, rectangle);
    block->block_sprite = sfSprite_copy(sheet);
    block->type = top_right;
    sfSprite_setScale(block->block_sprite, (sfVector2f) {0.0596, 0.0596});
    return block;
}
