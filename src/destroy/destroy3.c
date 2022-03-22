/*
** EPITECH PROJECT, 2022
** destroy3.c
** File description:
** destroy"
*/

#include "scene.h"

void destroy_tower(tower_t **block)
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

void destroy_tower_circle(tower_t **tower)
{
    for (int i = 0; tower[i]->type != null; i++) {
        if (tower[i]->tower_type != none) {
            sfSprite_destroy(tower[i]->tower);
            sfCircleShape_destroy(tower[i]->circle);
        }
    }
}

void destroy_info(game_t *game)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(game->bg));
    sfSprite_destroy(game->bg);
    sfSprite_destroy(game->end_screen);
    sfSprite_destroy(game->game_bar);
    sfSprite_destroy(game->snd_vis);
    sfSprite_destroy(game->dialog);
    sfRectangleShape_destroy(game->filter);
    sfFont_destroy(game->font);
    sfText_destroy(game->info);
    sfText_destroy(game->money_text);
    free(game->sound_rect);
}

void destroy_all(game_t *game, map_t map, win_t *window, scene_t *scene)
{
    destroy_info(game);
    destroy_copy_sprite(game->path);
    destroy_tower_circle(game->tower);
    destroy_tower(game->tower);
    destroy_mob(game->mob, map.nb_mob);
    free(map.mob_path_x);
    free(map.mob_path_y);
    sfSprite_destroy(map.sheet);
    free_array(map.map);
    sfClock_destroy(window->dt.clock);
    sfRenderWindow_destroy(window->window);
    destroy_scene(scene);
    destroy_sound(game);
    free(game->str_money);
    sfText_destroy(game->score_text);
}

void restart_all(game_t *game, map_t map, scene_t *scene)
{
    destroy_info(game);
    destroy_copy_sprite(game->path);
    destroy_tower_circle(game->tower);
    destroy_tower(game->tower);
    destroy_mob(game->mob, map.nb_mob);
    free(map.mob_path_x);
    free(map.mob_path_y);
    sfSprite_destroy(map.sheet);
    free_array(map.map);
    destroy_scene(scene);
    destroy_sound(game);
    free(game->str_money);
    game->score = 0;
}
