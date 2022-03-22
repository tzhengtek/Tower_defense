/*
** EPITECH PROJECT, 2022
** event.c
** File description:
** event
*/

#include "proto.h"

void key_pressed_condition(win_t *window)
{
    if (window->event.key.code == sfKeyEscape && window->state == in_menu)
        sfRenderWindow_close(window->window);
    if (window->event.key.code == sfKeyEscape && window->state == in_game)
        window->state = is_paused;
    if (window->event.key.code == sfKeyEscape && window->state == settings)
        window->state = in_menu;
}

void window_event(win_t *window, game_t *game)
{
    if (window->base_life <= 0 || game->nb_mob <= 0)
        window->state = end_game;
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (window->event.type == sfEvtKeyPressed)
            key_pressed_condition(window);
    }
}
