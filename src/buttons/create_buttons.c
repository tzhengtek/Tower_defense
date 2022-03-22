/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** create_buttons
*/

#include "scene.h"

void (*set_button[12])() = {set_start, set_opt, set_quit, set_menu, set_rsm,
set_tur_buy, set_lsr_buy, set_slw_buy,
set_snp_buy, set_low, set_high, set_fps};

void make_button(button_t *button, sfSprite *sheet, int type,
sfVector2f pos)
{
    sfFloatRect bounds;

    button->sprite = sfSprite_copy(sheet);
    button->type = type;
    (*set_button[type])(button);
    sfSprite_setPosition(button->sprite, pos);
    bounds = sfSprite_getGlobalBounds(button->sprite);
    sfSprite_setOrigin(button->sprite,
    (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfSprite_setScale(button->sprite, (sfVector2f){0.7, 0.7});
}
