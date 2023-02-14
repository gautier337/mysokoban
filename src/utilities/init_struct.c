/*
** EPITECH PROJECT, 2022
** init_struct
** File description:
** init_struct
*/

#include "header.h"

int check_condition(game_t *game, int y)
{
    for (int x = 0; game->map[y][x] != '\0'; x++) {
        if (game->map[y][x] == 'P') {
            game->player->x = x;
            game->player->y = y;
            return 0;
        }
    }
    return -1;
}

int get_position_player(game_t *game)
{
    game->player = malloc(sizeof(player_t));
    for (int y = 0; game->map[y] != NULL; y++)
        if (check_condition(game, y) == 0)
            return 0;
    return 84;
}

int check_nbr_box(game_t *game)
{
    int nbr = nbr_box(game);
    int nbr_baskett = nbr_basket(game);

    if (nbr < nbr_baskett)
        return 84;
    return 0;
}

int init(game_t *game, char **argv)
{
    if (!(game->map = map_from_file(argv[1])))
        return 84;
    if (check_nbr_box(game) == 84)
        return 84;
    if (get_position_player(game) == 84)
        return 84;
    game->status = -1;
    if (init_box(game) == 84)
        return 84;
    if (init_basket(game) == 84)
        return 84;
    return 0;
}
