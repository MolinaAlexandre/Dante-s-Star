/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#ifndef _MY_H_
    #define _MY_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include "struct.h"

char **my_taballoc(char *str, int count_letter, int no_letter, int j);
char **my_str_to_word_array(char *str, char **test);
int my_strlen(char *str);
void my_free(char **my_map, char *buffer);
int error_handling(int argc, char **argv);
char *open_file(int argc, char **argv);
char **my_parsing(char *str);
int count_rows(char **map);
int count_cols(char **map);
int my_algorithm(maze_s *maze, int rows, int cols);

#endif /* _MY_H_ */
