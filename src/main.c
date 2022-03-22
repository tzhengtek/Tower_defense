/*
** EPITECH PROJECT, 2022
** lain.c
** File description:
** main
*/

#include "my.h"
#include "proto.h"

int main(int ac, char **av)
{
    (void)ac;
    map_t map;

    if ((map = gestion_map(av[1])).type != ok)
        return 84;
    return game_window(map);
}
