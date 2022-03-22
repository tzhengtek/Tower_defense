/*
** EPITECH PROJECT, 2022
** create_window.c
** File description:
** create_window
*/

#include "proto.h"

sfRenderWindow *create_video(void)
{
    int width = 1920;
    int height = 1080;
    sfVideoMode mode = {width, height, 32};

    sfRenderWindow *window =
    sfRenderWindow_create(mode, "Window", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return window;
}
