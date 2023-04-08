/*
** EPITECH PROJECT, 2023
** generator
** File description:
** test
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "error_handling.h"
#include "utils.h"

int set_path(algo_t *gen, int path, int x, int y)
{
    gen->dx = 0;
    gen->dy = 0;
    switch (path){
    case 0: gen->dx = 1;
            break;
    case 1: gen->dy = 1;
            break;
    case 2: gen->dx = -1;
            break;
    default: gen->dy = -1;
            break;
    }
    gen->x1 = x + gen->dx;
    gen->y1 = y + gen->dy;
    gen->x2 = gen->x1 + gen->dx;
    gen->y2 = gen->y1 + gen->dy;
    return path;
}

void algo_main(char *maze, algo_t *gen, int x, int y)
{
    int path;
    int count = 0;
    path = rand() % 4;
    while (count < 4){
        path = set_path(gen, path, x, y);
        if (gen->x2 > 0 && gen->x2 < gen->width && gen->y2 > 0 &&
gen->y2 < gen->height && maze[gen->y1 * gen->width + gen->x1] == 1 &&
maze[gen->y2 * gen->width + gen->x2] == 1){
            maze[gen->y1 * gen->width + gen->x1] = 0;
            maze[gen->y2 * gen->width + gen->x2] = 0;
            x = gen->x2;
            y = gen->y2;
            path = rand() % 4;
            count = 0;
        } else {
            path = (path + 1) % 4;
            count ++;
        }
    }
}

void algo_hub(char *maze, algo_t *gen)
{
    for (int x = 0; x < gen->width * gen->height; x++){
        maze[x] = 1;
    }
    maze[1 * gen->width + 1] = 0;
    srand(time(0));
    for (int y = 1; y < gen->height; y += 2){
        for (int x = 1; x < gen->width; x += 2){
            algo_main(maze, gen, x, y);
        }
    }
    maze[0 * gen->width + 1] = 0;
    maze[(gen->height - 1) * gen->width + (gen->width - 2)] = 0;
}

void assign_struct(algo_t *gen, char *av[])
{
    gen->real_width = atoi(av[1]);
    gen->real_height = atoi(av[2]);
    if (gen->real_width % 2 != 1){
        gen->width = gen->real_width + 1;
    } else {
        gen->width = gen->real_width + 2;
    }
    if (gen->real_height % 2 != 1){
        gen->height = gen->real_height + 1;
    } else {
        gen->height = gen->real_height + 2;
    }
}

int main(int ac,char *av[])
{
    error_handling(ac, av);
    algo_t gen;
    char *maze;
    assign_struct(&gen, av);
    maze = malloc(sizeof(char) * gen.width * gen.height);
    algo_hub(maze, &gen);
    print_maze(maze, &gen);
    free(maze);
}
