/*
** EPITECH PROJECT, 2022
** check_status
** File description:
** check_status
*/

#include "header.h"

int check_status(game_t *game)
{
    if (!game)
        return 84;
    if (check_lose_box(game) == 1) {
        game->status = 1;
        return game->status;
    }
    if (check_win(game) == 1) {
        game->status = 0;
        return game->status;
    }
    return game->status;
}
