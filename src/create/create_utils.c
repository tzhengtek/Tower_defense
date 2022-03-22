/*
** EPITECH PROJECT, 2022
** create_utils.c
** File description:
** create_utils
*/

#include "scene.h"

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *textures = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, textures, sfFalse);
    return sprite;
}

sfVector2f create_vector(float x, float y)
{
    sfVector2f point;

    point.x = x;
    point.y = y;
    return point;
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rectangle;

    rectangle.top = top;
    rectangle.left = left;
    rectangle.width = width;
    rectangle.height = height;
    return rectangle;
}

win_t create_window(void)
{
    win_t window;

    window.window = create_video();
    init_time(&window.dt);
    window.state = in_menu;
    window.mouse.type = none;
    window.base_life = 1;
    return window;
}
