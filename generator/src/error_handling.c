/*
** EPITECH PROJECT, 2023
** B2 - Elementary programming in C
** File description:
** error_handling
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void special_case(int ac, char *av[])
{
    if (atoi(av[1]) < 0 || atoi(av[2]) < 0){
        write(2, "Wrong size please be superior than 0\n", 38);
        exit(84);
    }
    if (atoi(av[1]) == 0 || atoi(av[2]) == 0){
        exit(0);
    }
}

void error_handling(int ac, char *av[])
{
    if (ac < 3 ){
        write(2, "Not enought arguments.\n", 24);
        exit(84);
    }
    if (ac > 4){
        write(2, "Too many arguments.\n", 21);
        exit(84);
    }
    char *ptr;
    for (int i = 1; i < 3; i++){
        strtod(av[i], &ptr);
        if (strlen(ptr) != 0){
            write(2, "./generator [WIDTH][HEIGHT] [perfect].\n", 40);
            exit(84);
        }
    }
    special_case(ac, av);
}

