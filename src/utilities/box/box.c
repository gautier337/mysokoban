/*
** EPITECH PROJECT, 2022
** box
** File description:
** box
*/

#include "header.h"

int nbr_box(game_t *game)
{
    int nbr = 0;

    for (int y = 0; game->map[y] != NULL; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++)
            nbr = (game->map[y][x] == 'X') ? nbr += 1 : nbr;
    }
    if (nbr <= 0)
        return -1;
    return nbr;
}

int check_compare(game_t *game, int idx, int y, int x)
{
    if (!game)
        return -1;
    if (game->map[y][x] == 'X') {
        game->box[idx]->x = x;
        game->box[idx]->y = y;
        idx++;
    }
    return idx;
}

int get_position_box(game_t *game)
{
    int nbr = nbr_box(game);
    int idx = 0;

    if (!game || nbr == -1)
        return 84;
    for (int y = 0; idx < nbr; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            idx = check_compare(game, idx, y, x);
    return 0;
}

int init_box(game_t *game)
{
    int nbr = nbr_box(game);

    if (nbr == -1)
        return 84;
    game->box = malloc(sizeof(game->box) * nbr);
    for (int i = 0; i < nbr; i++)
        game->box[i] = malloc(sizeof(game->box));
    for (int i = 0; i < nbr; i++) {
        game->box[i]->x = 0;
        game->box[i]->y = 0;
    }
    if (get_position_box(game) == 84)
        return 84;
    return 0;
}
