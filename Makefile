##
## EPITECH PROJECT, 2022
## Unix_System_Programming
## File description:
## Makefile
##

CFLAGS = -g3 -ggdb -lncurses -Wno-unused-command-line-argument -Iinclude

SRC =   $(wildcard src/*.c)	\
		$(wildcard src/lib/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -lncurses -Iinclude -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
