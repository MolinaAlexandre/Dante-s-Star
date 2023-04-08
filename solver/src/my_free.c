/*
** EPITECH PROJECT, 2023
** solver
** File description:
** my_free
*/

#include "my.h"

void my_free(char **my_map, char *buffer)
{
    int i = 0;
    while (my_map[i] != NULL) {
        free(my_map[i]);
        i++;
    }
    free(my_map);
    free(buffer);
}
