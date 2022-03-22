/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-artyom.tillon
** File description:
** malloc_buttons
*/

#include "my.h"
#include "scene.h"

int malloc_buttons(scene_t *scene, int nbr_of_buttons)
{
    scene->buttons = malloc(sizeof(button_t) * nbr_of_buttons);
    if (scene->buttons == NULL) {
        print_error("MEM_FAIL: Couldn't malloc buttons");
        return -1;
    }
    return 0;
}
