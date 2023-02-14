/*
** EPITECH PROJECT, 2021
** count_words
** File description:
** my_header
*/

#ifndef my
    #define my

    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>

    #include "lib.h"

typedef struct box {
    int x;
    int y;
} box_t;

typedef struct basket {
    int x;
    int y;
    int status;
} basket_t;

typedef struct player {
    int x;
    int y;
} player_t;

typedef struct game {
    char **map;
    player_t *player;
    box_t **box;
    basket_t **basket;
    int status;
} game_t;

int sokoban(int argc, char **argv);
int check_map_errors(char **map);
int check_ascii_map(char *map);
char **map_from_file(char const *filepath);
int get_control(int ch, game_t *game);
int display_map(char **map);
int init(game_t *game, char **argv);
int edit_y(game_t *game, bool i);
int edit_x(game_t *game, bool i);
int init_box(game_t *game);
int nbr_box(game_t *game);
int get_position_box(game_t *game);
int check_lose_box(game_t *game);
int check_status(game_t *game);
int check_space(int ch, game_t *game, char **argv);
int check_win(game_t *game);
int init_basket(game_t *game);
int nbr_basket(game_t *game);
int game_playing(game_t *game, char **argv);
void settings_window(void);
int get_lines(char const *filepath);
int check_wsize(game_t *game, char const *filepath);
int get_max_cols(int *list, char const *filepath);
int *get_list_bytes(char const *filepath);

#endif
