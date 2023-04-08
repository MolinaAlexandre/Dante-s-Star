/*
** EPITECH PROJECT, 2023
** solver
** File description:
** error_handling
*/

#include "my.h"

int error_handling_2(int argc, char **argv)
{
    int i = 0;
    char *buffer = open_file(argc, argv);
    while (buffer[i] != '\0') {
        i++;
    }
    if (buffer[i - 1] == 'X') {
        write(2, "Careful, your maze don't have exit\n", 35);
        free(buffer);
        return 84;
    }
    if (buffer[0] == '\0') {
        write(2, "Your map is empty\n", 19);
        free(buffer);
        return 84;
    }
    free(buffer);
    return 0;
}

int error_handling(int argc, char **argv)
{
    int i = 0;
    if (argc != 2) {
        write(2, "Check your number of arguments !\n", 34);
        return 84;
    }
    char *buffer = open_file(argc, argv);
    if (buffer[0] == 'X') {
        write(2, "Careful, your maze don't have entry\n", 35);
        free(buffer);
        return 84;
    }
    free(buffer);
    return error_handling_2(argc, argv);
}
