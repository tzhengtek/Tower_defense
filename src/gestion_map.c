/*
** EPITECH PROJECT, 2022
** gestion_map.c
** File description:
** gestion_map
*/

#include "my.h"
#include "proto.h"

int good_map_check(char **map)
{
    if (correct_map(map) == 84) {
        print_error("MAP_ERR: Wrong elements on map\n");
        return 84;
    }
    if (size_map(map) == 84) {
        print_error("MAP_ERR: Line size differs\n");
        return 84;
    }
    if (size_map(map) == 1) {
        print_error("MAP_ERR: Lines column differ to 32\n");
        return 84;
    }
    return 0;
}

int checking_map(map_t *map)
{
    if (good_map_check(map->map) == 84)
        return 84;
    if (check_spawn(map) == 84) {
        print_error("MAP_ERR: Too many/not enough spawnpoints\n");
        return 84;
    }
    if (check_castle(map) == 84) {
        print_error("MAP_ERR: Too many/not enough castles\n");
        return 84;
    }
    if (check_path(map->map) == 84) {
        print_error("MAP_ERR: No way to reach the castle\n");
        return 84;
    }
    return 0;
}

map_t gestion_map(char *filepath)
{
    map_t map;
    char *str_map = get_map(filepath);

    if (str_map == NULL)
        return map;
    if (my_strcmp(str_map, "LINE") == 0) {
        print_error("MAP_ERR: Lines differ to 18\n");
        return map;
    }
    map.map = str_to_array(str_map, '\n', '\0');
    free(str_map);
    if (checking_map(&map) == 84) {
        free_array(map.map);
        return map;
    }
    map.type = ok;
    return map;
}
