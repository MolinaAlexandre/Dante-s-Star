##
## EPITECH PROJECT, 2023
## Dante
## File description:
## Generator Makefile
##

CC = gcc

CFLAGS = -I./includes\

SRC =	src/algorithm.c\
		src/utils.c\
		src/error_handling.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *.gcda *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
