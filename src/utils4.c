/*
** EPITECH PROJECT, 2022
** utils4.c
** File description:
** utils
*/

#include "proto.h"
#include "my.h"

int check_inside_rect(sfVector2f rect, sfVector2i mouse, int size)
{
    if ((float)mouse.x >= rect.x && (float)mouse.x <= rect.x + size) {
        if ((float)mouse.y >= rect.y && (float)mouse.y <= rect.y + size)
            return 1;
    }
    return 0;
}

void int_char(game_t *game)
{
    free(game->str_money);
    game->str_money = int_to_char(game->money);
}
