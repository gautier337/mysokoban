/*
** EPITECH PROJECT, 2022
** check_o
** File description:
** o
*/

#include "header.h"

int nbr_basket(game_t *game)
{
    int nbr = 0;

    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            nbr = (game->map[y][x] == 'O') ? nbr += 1 : nbr;
    if (nbr <= 0)
        return -1;
    return nbr;
}

int check_compare_basket(game_t *game, int idx, int y, int x)
{
    if (!game)
        return -1;
    if (game->map[y][x] == 'O') {
        game->basket[idx]->x = x;
        game->basket[idx]->y = y;
        idx++;
    }
    return idx;
}

int get_position_basket(game_t *game)
{
    int nbr = nbr_box(game);
    int idx = 0;

    if (!game || nbr == -1)
        return 84;
    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            idx = check_compare_basket(game, idx, y, x);
    return 0;
}

int init_basket(game_t *game)
{
    int nbr = nbr_basket(game);

    if (nbr == -1)
        return 84;
    game->basket = malloc(sizeof(basket_t *) * nbr + 1);
    for (int i = 0; i < nbr; i++) {
        game->basket[i] = malloc(sizeof(basket_t));
        game->basket[i]->x = 0;
        game->basket[i]->y = 0;
        game->basket[i]->status = 0;
    }
    get_position_basket(game);
    if (nbr <= 0)
        return 84;
    return 0;
}
