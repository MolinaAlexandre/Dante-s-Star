##
## EPITECH PROJECT, 2023
## Dante
## File description:
## Solver Makefile
##

RM	=	rm -f

SRC	=	src/main.c	\
		src/my_str_to_word_array.c\
		src/my_free.c	\
		src/error_handling.c\
		src/my_open_file.c	\
		src/my_counter.c\
		src/my_algorithm.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-I./includes -g3

all:	solver

solver:	$(OBJ)
	gcc $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) *#
	$(RM) src/*.o
	$(RM) src/*~
	$(RM) src/*#

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all solver clean fclean re
