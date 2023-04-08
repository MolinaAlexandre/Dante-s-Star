/*
** EPITECH PROJECT, 2023
** solver
** File description:
** my_algorithm
*/

#include "my.h"

int my_algorithm_2(maze_s *maze, int rows, int cols)
{
    if (rows - 1 > -1 && maze->my_map[rows - 1][cols] == '*') {
        maze->my_map[rows - 1][cols] = 'o';
        if (my_algorithm(maze, rows - 1, cols) == 1) {
            return 1;
        }
    }
    if (rows + 1 < maze->nb_rows && maze->my_map[rows + 1][cols] == '*') {
        maze->my_map[rows + 1][cols] = 'o';
        if (my_algorithm(maze, rows + 1, cols) == 1) {
            return 1;
        }
    }
    maze->my_map[rows][cols] = 'b';
    return 0;
}

int my_algorithm(maze_s *maze, int rows, int cols)
{
    if (rows == maze->nb_rows - 1 && cols == maze->nb_cols - 1)
        return 1;
    if (cols + 1 < maze->nb_cols && maze->my_map[rows][cols + 1] == '*') {
        maze->my_map[rows][cols + 1] = 'o';
        if (my_algorithm(maze, rows, cols + 1) == 1) {
            return 1;
        }
    }
    if (cols - 1 > -1 && maze->my_map[rows][cols - 1] == '*') {
        maze->my_map[rows][cols - 1] = 'o';
        if (my_algorithm(maze, rows, cols - 1) == 1) {
            return 1;
        }
    }
    int nb = my_algorithm_2(maze, rows, cols);
    if (nb == 1) {
        return 1;
    }
    return 0;
}
