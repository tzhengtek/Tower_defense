/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** scene
*/

#ifndef SCENE_H_
    #define SCENE_H_
    #include "proto.h"
    #define WIDTH 1920
    #define HEIGHT 1080
    #define NB_BUTTONS 3

int on_button(button_t *button, win_t *window, int state, game_t *game);
int button_clicked(button_t *button, win_t *window, int state, game_t *game);
void make_button(button_t *button, sfSprite *sheet, int type,
sfVector2f pos);
int malloc_buttons(scene_t *scene, int nbr_of_buttons);
void set_start(button_t *button);
void set_opt(button_t *button);
void set_quit(button_t *button);
void set_menu(button_t *button);
void set_rsm(button_t *button);
void set_tur_buy(button_t *button);
void set_lsr_buy(button_t *button);
void set_slw_buy(button_t *button);
void set_snp_buy(button_t *button);
void set_high(button_t *button);
void set_low(button_t *button);
void set_fps(button_t *button);

#endif /* !SCENE_H_ */
