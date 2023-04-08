/*
** EPITECH PROJECT, 2023
** solver
** File description:
** main
*/

#include "my.h"

void print_next_row(maze_s *maze, int *i, int *j)
{
    (*i)++;
    (*j) = 0;
    if (*i == maze->nb_rows) {
        return;
    }
    printf("\n");
}

void my_programm_2(maze_s *maze, char *buffer)
{
    int i = 0;
    int j = 0;
    while (i < maze->nb_rows) {
        j++;
        if (maze->my_map[i][j] == 'b') {
            printf("*");
        } else {
            printf("%c", maze->my_map[i][j]);
        }
        if (j == (maze->nb_cols - 1)) {
            print_next_row(maze, &i, &j);
            continue;
        }
    }
    my_free(maze->my_map, buffer);
}

int my_programm(int argc, char **argv, maze_s *maze)
{
    char *buffer = open_file(argc, argv);
    maze->my_map = my_parsing(buffer);
    maze->nb_rows = count_rows(maze->my_map);
    maze->nb_cols = count_cols(maze->my_map);
    maze->my_map[0][0] = 'o';
    my_algorithm(maze, 0, 0);
    if (maze->my_map[maze->nb_rows - 1][maze->nb_cols - 1] != 'o') {
        my_free(maze->my_map, buffer);
        printf("No solution found");
        return 0;
    }
    my_programm_2(maze, buffer);
    return 0;
}

int main(int argc, char **argv)
{
    maze_s *maze = malloc(sizeof(maze_s));
    if (error_handling(argc, argv) == 84) {
        free(maze);
        return 84;
    }
    my_programm(argc, argv, maze);
    free(maze);
    return 0;
}
