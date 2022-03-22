/*
** EPITECH PROJECT, 2022
** display_game.c
** File description:
** display_game
*/

#include "scene.h"
#include "my.h"

void display_scene(win_t *window, scene_t *scene, int button_nbr, game_t *game)
{
    if (window->state == in_game) {
        for (int i = button_nbr / 2; i < button_nbr; i++) {
            sfRenderWindow_drawSprite
            (window->window, scene->buttons[i].sprite, NULL);
            button_clicked(&scene->buttons[i], window, window->state, game);
        }
    } else if (window->state == settings) {
        for (int i = button_nbr / 2; i < button_nbr; i++) {
            sfRenderWindow_drawSprite
            (window->window, scene->buttons[i].sprite, NULL);
            button_clicked(&scene->buttons[i], window, window->state, game);
        }
    } else {
        for (int i = 0; i < button_nbr; i++) {
            sfRenderWindow_drawSprite
            (window->window, scene->buttons[i].sprite, NULL);
            button_clicked(&scene->buttons[i], window, window->state, game);
        }
    }
}

void restart_state(win_t *window, game_t *game, map_t map)
{
    destroy_mob(game->mob, NB_MOB);
    game->mob = create_all_mob(map, game->path);
    game->money = 400;
    for (int i = 0; game->tower[i]->type != null; i++) {
        if (game->tower[i]->tower_type != none) {
            sfSprite_destroy(game->tower[i]->tower);
            sfCircleShape_destroy(game->tower[i]->circle);
            game->tower[i]->tower_type = none;
        }
    }
    window->state = in_menu;
}

void display_end_game(win_t *window, game_t *game, scene_t *scene)
{
    if (window->state == end_game) {
        if (window->base_life <= 0)
            sfSprite_setTextureRect(game->end_screen, game->lose);
        else
            sfSprite_setTextureRect(game->end_screen, game->win);
        game->str_score = int_to_char(game->score);
        sfText_setString(game->score_text, game->str_score);
        free(game->str_score);
        sfText_setPosition(game->score_text,
        (sfVector2f){WIDTH / 2, HEIGHT / 2 - 100});
        sfText_setScale(game->score_text, (sfVector2f){1.5, 1.5});
        sfRenderWindow_drawSprite(window->window, game->end_screen, NULL);
        sfRenderWindow_drawText(window->window, game->score_text, NULL);
        display_scene(window, &scene[2], 1, game);
        window_event(window, game);
        display_scene(window, &scene[2], 1, game);
    }
}

void display_start_game(scene_t *scene, win_t *window, game_t *game, map_t map)
{
    if (window->state == restart)
        restart_state(window, game, map);
    if (window->state == in_menu) {
        update_time(&window->dt);
        sfRenderWindow_drawSprite(window->window, game->bg, NULL);
        window_event(window, game);
        display_scene(window, &scene[0], 3, game);
    }
    if (window->state == settings) {
        update_time(&window->dt);
        sfRenderWindow_drawSprite(window->window, game->bg, NULL);
        sfRenderWindow_drawSprite(window->window, game->snd_vis, NULL);
        window_event(window, game);
        display_scene(window, &scene[0], 6, game);
    }
}

void display_game(scene_t *scene, win_t *window, game_t *game, map_t map)
{
    if (window->state == in_game) {
        init_game(window, game, map);
        sfRenderWindow_drawSprite(window->window, game->game_bar, NULL);
        display_scene(window, &scene[1], 7, game);
        sfRenderWindow_drawText(window->window, game->money_text, NULL);
    }
    if (window->state == is_paused) {
        init_game(window, game, map);
        sfRenderWindow_drawSprite(window->window, game->game_bar, NULL);
        sfRenderWindow_drawRectangleShape(window->window, game->filter, NULL);
        display_scene(window, &scene[1], 7, game);
        sfRenderWindow_drawText(window->window, game->money_text, NULL);
    }
    display_start_game(scene, window, game, map);
    display_end_game(window, game, scene);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
}
