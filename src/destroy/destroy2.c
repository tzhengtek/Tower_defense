/*
** EPITECH PROJECT, 2022
** destroy2.c
** File description:
** destroy2
*/

#include "proto.h"

void destroy_copy_sprite(block_t **block)
{
    int i = 0;

    for (; block[i]->type != null; i++) {
        sfSprite_destroy(block[i]->block_sprite);
        free(block[i]);
    }
    sfSprite_destroy(block[i]->block_sprite);
    free(block[i]);
    free(block);
}

void destroy_sound(game_t *game)
{
    sfMusic_destroy(game->sfx.ost);
    sfSound_destroy(game->sfx.btn_click);
    sfSound_destroy(game->sfx.place);
    sfSoundBuffer_destroy(game->sfx.buff_clk);
    sfSoundBuffer_destroy(game->sfx.place_snd);
}

void destroy_scene(scene_t *scene)
{
    for (int i = 0; i < 6; i++)
        sfSprite_destroy(scene[0].buttons[i].sprite);
    for (int i = 0; i < 7; i++)
        sfSprite_destroy(scene[1].buttons[i].sprite);
    for (int i = 0; i < 1; i++)
        sfSprite_destroy(scene[2].buttons[i].sprite);
    free(scene[0].buttons);
    free(scene[1].buttons);
    free(scene[2].buttons);
    free(scene);
}

void destroy_game_info(game_t *game)
{
    sfSprite_destroy(game->bg);
    sfText_destroy(game->info);
    sfFont_destroy(game->font);
    sfRectangleShape_destroy(game->filter);
    sfSprite_destroy(game->dialog);
    sfSprite_destroy(game->game_bar);
}
