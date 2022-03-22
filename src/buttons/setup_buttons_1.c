/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** setup_buttons_1
*/

#include "scene.h"

void set_start(button_t *button)
{
    sfIntRect play = {1200, 2000, 600, 200};

    sfSprite_setTextureRect(button->sprite, play);
    button->idle = play;
    play.top += 200;
    button->hover = play;
    play.top += 200;
    button->click = play;
    button->clicked = sfFalse;
}

void set_opt(button_t *button)
{
    sfIntRect set = {600, 2000, 600, 200};

    sfSprite_setTextureRect(button->sprite, set);
    button->idle = set;
    set.top += 200;
    button->hover = set;
    set.top += 200;
    button->click = set;
    button->clicked = sfFalse;
}

void set_quit(button_t *button)
{
    sfIntRect exit = {1800, 2000, 600, 200};

    sfSprite_setTextureRect(button->sprite, exit);
    button->idle = exit;
    exit.top += 200;
    button->hover = exit;
    exit.top += 200;
    button->click = exit;
    button->clicked = sfFalse;
}

void set_menu(button_t *button)
{
    sfIntRect main = {0, 2000, 600, 200};

    sfSprite_setTextureRect(button->sprite, main);
    button->idle = main;
    main.top += 200;
    button->hover = main;
    main.top += 200;
    button->click = main;
    button->clicked = sfFalse;
}

void set_rsm(button_t *button)
{
    sfIntRect rsm = {2400,2000, 600, 200};

    sfSprite_setTextureRect(button->sprite, rsm);
    button->idle = rsm;
    rsm.top += 200;
    button->hover = rsm;
    rsm.top += 200;
    button->click = rsm;
    button->clicked = sfFalse;
}
