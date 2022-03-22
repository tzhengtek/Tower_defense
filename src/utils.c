/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "proto.h"
#include "my.h"

int size_maps(char *filepath)
{
    size_t size = 0;
    char *line = NULL;
    FILE *file = fopen(filepath, "r");
    int len = 0;
    int count = 0;
    int height = 0;

    if (file == NULL)
        return -1;
    len = getline(&line, &size, file);
    while (len != -1) {
        count += my_strlen(line);
        len = getline(&line, &size, file);
        height++;
    }
    fclose(file);
    free(line);
    if (height != LINE)
        return -1;
    return count;
}

char *get_map(char *filepath)
{
    int nb = 0;
    char *map = NULL;
    int show = 0;

    if (open_file(filepath) == -1)
        return NULL;
    nb = size_maps(filepath);
    if (nb == -1)
        return "LINE";
    map = malloc(sizeof(char) * (nb + 1));
    if (map == NULL)
        return NULL;
    show = read(open_file(filepath), map, nb);
    if (show <= 0)
        return NULL;
    map[show] = '\0';
    close(open_file(filepath));
    return map;
}

int max_size(int j, int count)
{
    if (j > count)
        count = j;
    return count;
}

int column_size(char **map)
{
    int count = 0;
    int i = 0;
    int j = 0;

    for (; map[i] != NULL; i++) {
        for (; map[i][j] != '\0'; j++);
        count = max_size(j, count);
    }
    return count;
}

int size_map(char **map)
{
    int len = my_strlen(map[0]);

    for (int i = 0; map[i] != NULL; i++) {
        if (my_strlen(map[i]) != len)
            return 84;
        if (my_strlen(map[i]) != 32)
            return 1;
    }
    return 0;
}
