/*
** EPITECH PROJECT, 2022
** create_checkpoint.c
** File description:
** create_checkpoint
*/

#include "proto.h"

int count_checkpoint(block_t **path)
{
    int count = 0;

    for (int i = 0; path[i]->type != null; i++) {
        if (path[i]->type == top_left)
            count++;
        if (path[i]->type == top_right)
            count++;
        if (path[i]->type == bot_left)
            count++;
        if (path[i]->type == bot_right)
            count++;
    }
    return count;
}

int condition_checkpoint(int tmp, sfVector2f *checkpoint, block_t *block)
{
    if (block->type == top_right) {
        checkpoint[tmp] = create_vector(block->position.x, block->position.y);
        tmp++;
    }
    if (block->type == bot_left) {
        checkpoint[tmp] = create_vector(block->position.x, block->position.y);
        tmp++;
    }
    if (block->type == bot_right) {
        checkpoint[tmp] = create_vector(block->position.x, block->position.y);
        tmp++;
    }
    if (block->type == top_left) {
        checkpoint[tmp] = create_vector(block->position.x, block->position.y);
        tmp++;
    }
    return tmp;
}

checkpoint_t *create_all_checkpoint(block_t **path, map_t map)
{
    int tmp = 1;
    checkpoint_t *checkpoint = malloc(sizeof(checkpoint_t));

    checkpoint->count = count_checkpoint(path) + 2;
    checkpoint->point_pos =
    malloc(sizeof(sfVector2f) * checkpoint->count);
    checkpoint->point_pos[0] =
    create_vector(map.start.x * SIZE, map.start.y * SIZE);
    for (int i = 0; path[i]->type != null; i++)
        tmp = condition_checkpoint(tmp, checkpoint->point_pos, path[i]);
    checkpoint->point_pos[tmp] =
    create_vector(map.end.x * SIZE, map.end.y * SIZE);
    checkpoint->tmp = 1;
    return checkpoint;
}
