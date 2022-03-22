/*
** EPITECH PROJECT, 2022
** game_window.c
** File description:
** game_window
*/

#include "my.h"
#include "scene.h"

void init_game(win_t *window, game_t *game, map_t map)
{
    int_char(game);
    sfText_setString(game->money_text, (const char *)game->str_money);
    update_time(&window->dt);
    window_event(window, game);
    display_window(*window, game->tower, game->bg, game->path);
    display_all_mob(window, game->mob, game->path, map);
    check_pose_tower(window, game, map);
    check_tower_attack(game, window);
}

int game_window(map_t map)
{
    win_t window = create_window();
    game_t game = create_game(&map);
    scene_t *scene = create_button(map.sheet);

    sfRenderWindow_setFramerateLimit(window.window, game.fps_state);
    sfWindow_setKeyRepeatEnabled((sfWindow *)window.window, sfFalse);
    sfMusic_play(game.sfx.ost);
    while (sfRenderWindow_isOpen(window.window))
        display_game(scene, &window, &game, map);
    destroy_all(&game, map, &window, scene);
    return 0;
}
