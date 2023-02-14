/*
** EPITECH PROJECT, 2022
** check_win
** File description:
** check_win
*/

#include "header.h"

int check_win(game_t *game)
{
    int nbr = nbr_box(game);

    if (!game)
        return 84;
    for (int i = 0; game->basket[i] != NULL; i++)
        if (game->map[game->basket[i]->y][game->basket[i]->x] != 'X')
            return -1;
    return 1;
}
