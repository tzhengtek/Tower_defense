/*
** EPITECH PROJECT, 2022
** create_utils2.c
** File description:
** create_utils2
*/

#include "my.h"
#include "scene.h"

sfSprite *create_background(map_t map)
{
    sfIntRect rectangle = create_rect(2000, 3000, 1920, 1080);
    sfSprite *bg;

    sfSprite_setTextureRect(map.sheet, rectangle);
    bg = sfSprite_copy(map.sheet);
    sfSprite_setPosition(bg, (sfVector2f) {0, 0});
    return bg;
}

void setup_sound(game_t *gm)
{
    gm->sfx.ost = sfMusic_createFromFile("./sprite/sfx/ost.ogg");
    gm->sfx.btn_click = sfSound_create();
    gm->sfx.place = sfSound_create();
    gm->sfx.buff_clk = sfSoundBuffer_createFromFile("./sprite/sfx/click.ogg");
    gm->sfx.place_snd = sfSoundBuffer_createFromFile("./sprite/sfx/place.ogg");
    sfSound_setBuffer(gm->sfx.btn_click, gm->sfx.buff_clk);
    sfSound_setBuffer(gm->sfx.place, gm->sfx.place_snd);
    sfMusic_setLoop(gm->sfx.ost, sfTrue);
    sfMusic_setVolume(gm->sfx.ost, 30);
}

void fill_sound_rect_array(sfIntRect **sound)
{
    *sound = malloc(sizeof(sfIntRect) * 11);
    (*sound)[0] = (sfIntRect){4920, 2360, 741, 200};
    (*sound)[1] = (sfIntRect){4920 + 741, 2360, 741, 200};
    (*sound)[2] = (sfIntRect){4920 + 741 * 2, 2360, 741, 200};
    (*sound)[3] = (sfIntRect){4920 + 741 * 3, 2360, 741, 200};
    (*sound)[4] = (sfIntRect){4920, 2560, 741, 200};
    (*sound)[5] = (sfIntRect){4920 + 741, 2560, 741, 200};
    (*sound)[6] = (sfIntRect){4920 + 741 * 2, 2560, 741, 200};
    (*sound)[7] = (sfIntRect){4920 + 741 * 3, 2560, 741, 200};
    (*sound)[8] = (sfIntRect){4920, 2760, 741, 200};
    (*sound)[9] = (sfIntRect){4920 + 741, 2760, 741, 200};
    (*sound)[10] = (sfIntRect){4920 + 741 * 2, 2760, 741, 200};
}

game_t create_game2(map_t *map)
{
    game_t game;
    create_mob_path(map);
    game.nb_mob = map->nb_mob;
    game.path = create_path(*map);
    game.tower = create_map(map);
    game.mob = create_all_mob(*map, game.path);
    game.bg = create_background(*map);
    game.end_screen = sfSprite_copy(game.bg);
    game.game_bar = sfSprite_copy(game.bg);
    game.snd_vis = sfSprite_copy(game.bg);
    game.dialog = sfSprite_copy(game.bg);
    game.filter = sfRectangleShape_create();
    game.font = sfFont_createFromFile("./sprite/goodtimesrg.otf");
    game.info = sfText_create();
    game.money_text = sfText_create();
    game.money = 600;
    game.str_money = int_to_char(game.money);
    game.sound_volume = 30;
    game.fps_state = 60;
    return game;
}

game_t create_game(map_t *map)
{
    game_t game = create_game2(map);
    game.score = 0;
    game.score_text = sfText_create();
    game.win = (sfIntRect){0, 3080, 1920, 1080};
    game.lose = (sfIntRect){1920, 3080, 1920, 1080};
    fill_sound_rect_array(&game.sound_rect);
    sfText_setFont(game.score_text, game.font);
    sfText_setFont(game.money_text, game.font);
    sfText_setString(game.money_text, game.str_money);
    sfText_setPosition(game.money_text, (sfVector2f){200, 70});
    sfSprite_setOrigin(game.snd_vis, (sfVector2f){741 / 2, 200 / 2});
    sfSprite_setPosition(game.snd_vis, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfSprite_setTextureRect(game.snd_vis, (sfIntRect){7143, 2360, 741, 200});
    sfSprite_setTextureRect(game.dialog, (sfIntRect){4920, 2180, 869, 180});
    sfSprite_setTextureRect(game.end_screen, (sfIntRect){0, 3080, 1920, 1080});
    sfRectangleShape_setFillColor(game.filter, (sfColor){0, 0, 0, 200});
    sfRectangleShape_setSize(game.filter, (sfVector2f){1920, 1080});
    sfSprite_setTextureRect(game.game_bar, (sfIntRect){4920, 2000, 1920, 180});
    setup_sound(&game);
    return game;
}
