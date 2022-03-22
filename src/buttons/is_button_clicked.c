/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** is_button_clicked
*/

#include "scene.h"

void exec_sound_button
(game_t *game, button_t *button)
{
    if (button->type == low) {
        if (game->sound_volume > 0) {
            game->sound_volume -= 10;
            sfSprite_setTextureRect(game->snd_vis,
            game->sound_rect[game->sound_volume / 10]);
        }
        sfMusic_setVolume(game->sfx.ost, game->sound_volume);
    }
    if (button->type == high) {
        if (game->sound_volume < 100) {
            game->sound_volume += 10;
            sfSprite_setTextureRect(game->snd_vis,
            game->sound_rect[game->sound_volume / 10]);
        }
        sfMusic_setVolume(game->sfx.ost, game->sound_volume);
    }
}

void fps_button(game_t *game, button_t *button, win_t *window)
{
    if (game->fps_state == 30) {
        game->fps_state = 60;
        button->idle.left = 9500;
        button->hover.left = 9500;
        button->click.left = 9500;
        sfRenderWindow_setFramerateLimit(window->window, game->fps_state);
    } else if (game->fps_state == 60) {
        game->fps_state = 144;
        button->idle.left = 10000;
        button->hover.left = 10000;
        button->click.left = 10000;
        sfRenderWindow_setFramerateLimit(window->window, game->fps_state);
    } else {
        game->fps_state = 30;
        button->idle.left = 9000;
        button->hover.left = 9000;
        button->click.left = 9000;
        sfRenderWindow_setFramerateLimit(window->window, game->fps_state);
    }
}

void exec_button(button_t *button, win_t *window, int state, game_t *game)
{
    if (button->type == quit)
        sfRenderWindow_close(window->window);
    if (button->type == start
    || (button->type == resume && state == is_paused))
        window->state = in_game;
    if (button->type == menu && (state == is_paused || state == end_game))
        window->state = restart;
    if (button->type == options && state == in_menu)
        window->state = settings;
    if (button->type == turret_sp)
        window->mouse.type = normal;
    if (button->type == laser_sp)
        window->mouse.type = laser;
    if (button->type == slow_sp)
        window->mouse.type = slower;
    if (button->type == snp_sp)
        window->mouse.type = sniper;
    exec_sound_button(game, button);
    if (button->type == fps)
        fps_button(game, button, window);
}

void play_sound_reset_visual
(button_t *button, game_t *game, win_t *window, int state)
{
    if (!button->clicked) {
        button->clicked = sfTrue;
        sfSound_play(game->sfx.btn_click);
        exec_button(button, window, state, game);
    }
}

int button_clicked(button_t *button, win_t *window, int state, game_t *game)
{
    if (on_button(button, window, state, game) != idle
    && window->event.mouseButton.button == sfMouseLeft) {
        sfSprite_setTextureRect(button->sprite, button->click);
        if (window->event.type == sfEvtMouseButtonReleased
        && window->event.mouseButton.button == sfMouseLeft) {
            play_sound_reset_visual(button, game, window, state);
            sfSprite_setTextureRect(button->sprite, button->hover);
            return 0;
        }
        button->clicked = sfFalse;
    }
    return 0;
}
