/*
** EPITECH PROJECT, 2023
** generator
** File description:
** utils
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include <stdbool.h>

bool is_pair(int nb, int heigth)
{
    if (nb % 2 == 0){
        return true;
    }
    return false;
}

void print_char(char *maze, int width, int x, int y)
{
    if (maze[y * width + x] == 1){
        printf("X");
    } else {
        printf("*");
    }
}

void print_maze_pair(char *maze, algo_t *gen)
{
    int x;
    int y;
    bool is_pair_w = is_pair(gen->real_width, gen->width);
    int print_w = gen->width;
    if (is_pair_w == false){
        print_w -= 1;
    }
    for (y = 1; y < gen->height - 1; y++){
        for (x = 1; x < print_w; x++){
            print_char(maze, gen->width, x, y);
        }
        printf("\n");
    }
    for (x = 1; x < print_w - 1; x++){
        print_char(maze, gen->width, x, y);
    }
    printf("*");
}

void print_maze_impair(char *maze, algo_t *gen)
{
    bool is_pair_w = is_pair(gen->real_width, gen->width);
    int print_w = gen->width;
    int x;
    int y;
    if (is_pair_w == false){
        print_w -= 1;
    }
    for (y = 1; y < gen->height - 2; y++){
        for (x = 1; x < print_w; x++){
            print_char(maze, gen->width, x, y);
        }
        printf("\n");
    }
    for (x = 1; x < print_w - 1; x++){
        print_char(maze, gen->width, x, y);
    }
    printf("*");
}

void print_maze(char *maze,algo_t *gen)
{
    bool is_pair_h = is_pair(gen->real_height,gen->height);
    if (is_pair_h == true){
        print_maze_pair(maze, gen);
    } else {
        print_maze_impair(maze, gen);
    }
}
