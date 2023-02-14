##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Gautier BONHUR
##

NAME			=	my_sokoban

SRC_MAIN		= main.c

SRC				=	$(addprefix src/, \
					sokoban.c \
					set_game.c \
					map_tools/load_map.c \
					map_tools/check_errors_map.c \
					utilities/init_struct.c \
					utilities/display_map.c \
					utilities/get_control.c \
					utilities/y.c \
					utilities/x.c \
					utilities/box/box.c \
					utilities/box/check_lose.c \
					utilities/check_status.c \
					utilities/basket/check_win.c \
					utilities/basket/basket.c \
					utilities/get_max_cols.c \
					lib/my_putchar.c \
					lib/my_revstr.c \
					lib/my_putstr.c \
					lib/my_lenght_int.c \
					lib/my_strcmp.c \
					lib/my_strlen.c \
					lib/my_strcat.c)

SRC_TESTS = tests/tests_main.c

OBJ				=			$(SRC:.c=.o)

OBJ_MAIN		=			$(SRC_MAIN:.c=.o)

CFLAGS 			= 			-I./includes

CRITERION		= 			--coverage -lcriterion

ln				=			-lncurses

all: 			$(NAME)

$(NAME):		$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(ln)

tests_run: $(OBJ)
	make re
	gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS) $(CRITERION)
	./unit_tests
	rm unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

fclean:			clean
	rm -f $(NAME)

re:	$(NAME)

.PHONY: fclean tests_run clean re make
