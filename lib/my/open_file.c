/*
** EPITECH PROJECT, 2021
** open.c
** File description:
** open
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open_file(char const *filepath)
{
    int fd = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 84;
    return fd;
}
