/*
** EPITECH PROJECT, 2022
** create_utils3.c
** File description:
** create_utils3
*/

#include "scene.h"

void set_buttons_on_launch2(scene_t *scene, sfSprite *sheet)
{
    make_button(&scene[1].buttons[0], sheet, resume,
    (sfVector2f){WIDTH / 2, HEIGHT / 2});
    make_button(&scene[1].buttons[1], sheet, menu,
    (sfVector2f){WIDTH / 2, (HEIGHT / 2) + 150});
    make_button(&scene[1].buttons[2], sheet, quit,
    (sfVector2f){WIDTH / 2, (HEIGHT / 2) + 300});
    make_button(&scene[1].buttons[3], sheet, turret_sp,
    (sfVector2f){(WIDTH / 2) + 300, 100});
    make_button(&scene[1].buttons[4], sheet, laser_sp,
    (sfVector2f){(WIDTH / 2) + 460, 100});
    make_button(&scene[1].buttons[5], sheet, slow_sp,
    (sfVector2f){(WIDTH / 2) + 620, 100});
    make_button(&scene[1].buttons[6], sheet, snp_sp,
    (sfVector2f){(WIDTH / 2) + 780, 100});
    make_button(&scene[2].buttons[0], sheet, quit,
    (sfVector2f){(WIDTH / 2), (HEIGHT / 2) + 150});
}

void set_buttons_on_launch(scene_t *scene, sfSprite *sheet)
{
    make_button(&scene[0].buttons[0], sheet, start,
    (sfVector2f){WIDTH / 2, HEIGHT / 2});
    make_button(&scene[0].buttons[1], sheet, options,
    (sfVector2f){WIDTH / 2, (HEIGHT / 2) + 150});
    make_button(&scene[0].buttons[2], sheet, quit,
    (sfVector2f){WIDTH / 2, (HEIGHT / 2) + 300});
    make_button(&scene[0].buttons[3], sheet, low,
    (sfVector2f){(WIDTH / 2) - ((WIDTH / 2) / 2), HEIGHT / 2});
    make_button(&scene[0].buttons[4], sheet, high,
    (sfVector2f){(WIDTH / 2) + ((WIDTH / 2) / 2), HEIGHT / 2});
    make_button(&scene[0].buttons[5], sheet, fps,
    (sfVector2f){WIDTH / 2, (HEIGHT / 2) + 300});
    sfSprite_setScale(scene[0].buttons[3].sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setScale(scene[0].buttons[4].sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setScale(scene[0].buttons[5].sprite, (sfVector2f){0.5, 0.5});
    set_buttons_on_launch2(scene, sheet);
}

scene_t *create_button(sfSprite *sheet)
{
    scene_t *scene = malloc(sizeof(scene_t) * 3);

    if (malloc_buttons(&scene[0], 6) == -1)
        return NULL;
    if (malloc_buttons(&scene[1], 7) == -1)
        return NULL;
    if (malloc_buttons(&scene[2], 1) == -1)
        return NULL;
    set_buttons_on_launch(scene, sheet);
    return scene;
}
