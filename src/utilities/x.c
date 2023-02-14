/*
** EPITECH PROJECT, 2022
** x_function
** File description:
** x_function
*/

#include "header.h"

int replace_x(game_t *game, bool i)
{
    if (i == true) {
        if (game->map[game->player->y][game->player->x - 1] == 'X'
            && game->map[game->player->y][game->player->x - 2] != '#')
            game->map[game->player->y][game->player->x - 2] = 'X';
        return 0;
    }
    if (game->map[game->player->y][game->player->x + 1] == 'X'
        && game->map[game->player->y][game->player->x + 2] != '#')
        game->map[game->player->y][game->player->x + 2] = 'X';
    return 0;
}

int x_game(game_t *game, bool i)
{
    if (i == true) {
        game->map[game->player->y][game->player->x] = ' ';
        replace_x(game, true);
        game->map[game->player->y][game->player->x - 1] = 'P';
        game->player->x = game->player->x - 1;
        return 0;
    }
    if (i == false) {
        game->map[game->player->y][game->player->x] = ' ';
        replace_x(game, false);
        game->map[game->player->y][game->player->x + 1] = 'P';
        game->player->x = game->player->x + 1;
        return 0;
    }
    return 0;
}

int edit_x(game_t *game, bool i)
{
    if (i == true &&
        game->map[game->player->y][game->player->x - 1] != '#' &&
        (!(game->map[game->player->y][game->player->x - 1] == 'X'
        && (game->map[game->player->y][game->player->x - 2] == '#'
        || game->map[game->player->y][game->player->x - 2] == 'X'))))
        return x_game(game, i);
    if (i == false &&
        game->map[game->player->y][game->player->x + 1] != '#' &&
        (!(game->map[game->player->y][game->player->x + 1] == 'X'
        && (game->map[game->player->y][game->player->x + 2] == '#'
        || game->map[game->player->y][game->player->x + 2] == 'X'))))
        return x_game(game, i);
    return 0;
}
