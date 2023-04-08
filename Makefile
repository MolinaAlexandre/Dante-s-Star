##
## EPITECH PROJECT, 2023
## Dante
## File description:
## Generic Makefile
##

CC = gcc

all:    sub

sub:
	cd ./solver/ && $(MAKE)
	cd ./generator/ && $(MAKE)

$(NAME): sub

clean:
	rm -f ./solver/solver\
	rm -f ./generator/generator\

fclean: clean
	rm -f $(NAME)

re: fclean sub

.PHONY: sub clean fclean re
