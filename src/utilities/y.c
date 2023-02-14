/*
** EPITECH PROJECT, 2022
** y_function
** File description:
** y_function
*/

#include "header.h"

int replace_y(game_t *game, bool i)
{
    if (i == true) {
        if (game->map[game->player->y - 1][game->player->x] == 'X'
            && game->map[game->player->y - 2][game->player->x] != '#'
            && game->map[game->player->y - 2][game->player->x] != 'X')
            game->map[game->player->y - 2][game->player->x] = 'X';
        return 0;
    }
    if (game->map[game->player->y + 1][game->player->x] == 'X'
        && game->map[game->player->y + 2][game->player->x] != '#'
        && game->map[game->player->y + 2][game->player->x] != 'X')
        game->map[game->player->y + 2][game->player->x] = 'X';
    return 0;
}

int y_game(game_t *game, bool i)
{
    if (i == true) {
        replace_y(game, true);
        game->map[game->player->y][game->player->x] = ' ';
        game->map[game->player->y - 1][game->player->x] = 'P';
        game->player->y = game->player->y - 1;
        return 0;
    }
    if (i == false) {
        replace_y(game, false);
        game->map[game->player->y][game->player->x] = ' ';
        game->map[game->player->y + 1][game->player->x] = 'P';
        game->player->y = game->player->y + 1;
    }
    return 0;
}

int edit_y(game_t *game, bool i)
{
    if (i == true &&
        game->map[game->player->y - 1][game->player->x] != '#' &&
        (!(game->map[game->player->y - 1][game->player->x] == 'X'
        && (game->map[game->player->y - 2][game->player->x] == '#'
        || game->map[game->player->y - 2][game->player->x] == 'X')))) {
        return y_game(game, true);
    }
    if (i == false &&
        game->map[game->player->y + 1][game->player->x] != '#' &&
        (!(game->map[game->player->y + 1][game->player->x] == 'X'
        && (game->map[game->player->y + 2][game->player->x] == '#'
        || game->map[game->player->y + 2][game->player->x] == 'X')))) {
        return y_game(game, false);
    }
    return 0;
}
