/*
** EPITECH PROJECT, 2023
** solver
** File description:
** open_file
*/

#include "my.h"

char *open_file(int argc, char **argv)
{
    struct stat statbuf;
    stat(argv[1], &statbuf);
    int fd = open(argv[1], O_RDONLY);
    int size = statbuf.st_size;
    char *buffer = malloc(sizeof(char) * size + 1);
    buffer[size] = '\0';
    int j = read(fd, buffer, size);
    close(fd);
    return buffer;
}
