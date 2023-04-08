/*
** EPITECH PROJECT, 2023
** solver
** File description:
** my_str_to_word_array
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int count_word(char *str)
{
    int i = 0;
    int count_word = 1;
    while (str[i] != '\0') {
        if (str[i] == '*' || str[i] == 'X') {
        } else {
            count_word += 1;
        }
        i += 1;
    }
    return count_word;
}

char **my_str_to_word_array(char *str, char **test)
{
    int j = 0;
    int k = 0;
    int l = my_strlen(str) + 1;
    int no_letter = 0;
    for (int m = 0, i = 0; m < l; m += 1, i += 1) {
        if (str[i] == '*' || str[i] == 'X') {
            test[j][k] = str[i];
            no_letter = 0;
            k++;
        } else {
            no_letter++;
        }
        if (no_letter == 1) {
            k = 0;
            j++;
        }
    }
    return test;
}

char **my_taballoc(char *str, int count_letter, int no_letter, int j)
{
    int nb_word = count_word(str);
    char **test = malloc(sizeof(char *) * (nb_word + 1));
    int l = my_strlen(str) + 1;
    for (int m = 0, i = 0; m < l; m += 1, i += 1) {
        if (str[i] == '*' || str[i] == 'X') {
            count_letter += 1;
            no_letter = 0;
        } else {
            no_letter = 1;
        }
        if (no_letter == 1 && count_letter != 0) {
            test[j] = malloc(sizeof(char) * count_letter);
            count_letter = 0;
            j += 1;
        }
    }
    test[j] = NULL;
    return test;
}
