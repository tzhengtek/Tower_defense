/*
** EPITECH PROJECT, 2022
** setup_buttons_3.c
** File description:
** setupt_buttons3
*/

#include "scene.h"

void set_snp_buy(button_t *button)
{
    sfIntRect buy_snp = {0, 2759, 159, 159};

    sfSprite_setTextureRect(button->sprite, buy_snp);
    button->idle = buy_snp;
    button->hover = buy_snp;
    button->click = buy_snp;
    button->clicked = sfFalse;
}

void set_fps(button_t *button)
{
    sfIntRect fps_but = {9000, 2000, 500, 500};

    sfSprite_setTextureRect(button->sprite, fps_but);
    button->idle = fps_but;
    button->hover = fps_but;
    button->click = fps_but;
    button->clicked = sfFalse;
}

void set_low(button_t *button)
{
    sfIntRect low = {9001, 0, 750, 1000};

    sfSprite_setTextureRect(button->sprite, low);
    button->idle = low;
    button->hover = low;
    low.top += 1000;
    button->click = low;
    button->clicked = sfFalse;
}

void set_high(button_t *button)
{
    sfIntRect high = {9750, 0, 750, 1000};

    sfSprite_setTextureRect(button->sprite, high);
    button->idle = high;
    button->hover = high;
    high.top += 1000;
    button->click = high;
    button->clicked = sfFalse;
}
