/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** is_on_button
*/

#include "scene.h"

int get_button_type2(button_t *button, int state)
{
    if (button->type == turret_sp && state == in_game)
        return turret_sp;
    if (button->type == laser_sp && state == in_game)
        return laser_sp;
    if (button->type == slow_sp && state == in_game)
        return slow_sp;
    if (button->type == snp_sp && state == in_game)
        return snp_sp;
    if (button->type == low && state == settings)
        return low;
    if (button->type == high && state == settings)
        return high;
    if (button->type == fps && state == settings)
        return fps;
    return idle;
}

int get_button_type(button_t *button, int state)
{
    if (button->type == start)
        return start;
    if (button->type == options && state == in_menu)
        return options;
    if (button->type == quit)
        return quit;
    if (button->type == howtoplay)
        return howtoplay;
    if (button->type == menu)
        return menu;
    if (button->type == resume && state == is_paused)
        return in_game;
    return get_button_type2(button, state);
}

void show_msg(char *msg, game_t *game, win_t *win, sfFloatRect pos)
{
    sfSprite_setPosition(game->dialog,
    (sfVector2f){pos.left - DIALOG_BOX_SIZE, 50});
    sfText_setString(game->info, msg);
    sfText_setFont(game->info, game->font);
    sfText_setPosition(game->info,
    (sfVector2f){pos.left - (DIALOG_BOX_SIZE - 40), 100});
    sfRenderWindow_drawSprite(win->window, game->dialog, NULL);
    sfRenderWindow_drawText(win->window, game->info, NULL);
}

void render_info(button_t *button, sfFloatRect hitbox, win_t *window,
game_t *game)
{
    if (button->type == turret_sp && window->state == in_game)
        show_msg("Turret: Shoots enemies til they die\n'Pew Pew!'\nCost: 60",
        game, window, hitbox);
    if (button->type == laser_sp && window->state == in_game)
        show_msg("Laser: Melts your opponents\n'RTX ON!'\nCost: 200",
        game, window, hitbox);
    if (button->type == slow_sp && window->state == in_game)
        show_msg("Freezer: Slows foes down\n'Gotta go fast!'\nCost: 280",
        game, window, hitbox);
    if (button->type == snp_sp && window->state == in_game)
        show_msg("Railgun: Slow but powerful!\n'I saw it coming from miles"
        " away!'\nCost: 550",
        game, window, hitbox);
}

int on_button(button_t *button, win_t *window, int state, game_t *game)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(button->sprite);
    sfVector2i pointer = sfMouse_getPosition((const sfWindow *)window->window);

    if (sfFloatRect_contains(&hitbox, (float)pointer.x, (float)pointer.y)) {
        sfSprite_setTextureRect(button->sprite, button->hover);
        render_info(button, hitbox, window, game);
        return get_button_type(button, state);
    } else if
    (!sfFloatRect_contains(&hitbox, (float)pointer.x, (float)pointer.y)) {
        sfSprite_setTextureRect(button->sprite, button->idle);
        return idle;
    }
    return idle;
}
