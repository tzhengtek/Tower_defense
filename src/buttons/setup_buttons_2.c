/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** setup_buttons_2
*/
#include "scene.h"

void set_tur_buy(button_t *button)
{
    sfIntRect buy_tur = {0, 2600, 159, 159};

    sfSprite_setTextureRect(button->sprite, buy_tur);
    button->idle = buy_tur;
    button->hover = buy_tur;
    button->click = buy_tur;
    button->clicked = sfFalse;
}

void set_lsr_buy(button_t *button)
{
    sfIntRect buy_lsr = {159, 2600, 159, 159};

    sfSprite_setTextureRect(button->sprite, buy_lsr);
    button->idle = buy_lsr;
    button->hover = buy_lsr;
    button->click = buy_lsr;
    button->clicked = sfFalse;
}

void set_slw_buy(button_t *button)
{
    sfIntRect buy_slw = {318, 2600, 159, 159};

    sfSprite_setTextureRect(button->sprite, buy_slw);
    button->idle = buy_slw;
    button->hover = buy_slw;
    button->click = buy_slw;
    button->clicked = sfFalse;
}
