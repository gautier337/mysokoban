/*
** EPITECH PROJECT, 2022
** box_check_lose
** File description:
** box
*/

#include "header.h"

int check_corner(game_t *game, int i)
{
    int lose = 0;
    int x = game->box[i]->x;
    int y = game->box[i]->y;

    if ((game->map[y - 1][x] == '#' && game->map[y][x - 1] == '#') ||
        (game->map[y - 1][x] == '#' && game->map[y][x + 1] == '#'))
        lose++;
    if ((game->map[y + 1][x] == '#' && game->map[y][x + 1] == '#') ||
        (game->map[y + 1][x] == '#' && game->map[y][x - 1] == '#'))
        lose++;
    if (lose == 1)
        return 1;
    return 0;
}

int check_lose_box(game_t *game)
{
    int nbr = nbr_box(game);
    int lose = 0;

    if (!game)
        return -1;
    get_position_box(game);
    for (int i = 0; i < nbr; i++)
        if (check_corner(game, i) == 1)
            lose++;
    if (lose == nbr)
        return 1;
    return 0;
}
