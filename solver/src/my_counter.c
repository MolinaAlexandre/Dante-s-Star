/*
** EPITECH PROJECT, 2023
** solver
** File description:
** my_counter
*/

#include "my.h"

char **my_parsing(char *str)
{
    int count_letter = 0;
    int no_letter = 0;
    int j = 0;
    char **tab = my_taballoc(str, count_letter, no_letter, j);
    tab = my_str_to_word_array(str, tab);
    return tab;
}

int count_rows(char **map)
{
    int nb_rows = 0;
    int i = 0;

    while (map[i] != NULL) {
        i++;
        nb_rows++;
    }
    return nb_rows;
}

int count_cols(char **map)
{
    int i = 0;
    int nb_cols = 0;

    while (map[0][i] != '\0') {
        i++;
        nb_cols++;
    }
    return nb_cols;
}
