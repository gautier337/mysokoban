/*
** EPITECH PROJECT, 2022
** get_control
** File description:
** get_control_full
*/

#include "header.h"

int check_space(int ch, game_t *game, char **argv)
{
    if (ch == ' ')
        if (init(game, argv) == 84)
            return 84;
    return 0;
}

int get_control(int ch, game_t *game)
{
    switch (ch) {
        case KEY_LEFT:
            edit_x(game, true);
            break;
        case KEY_RIGHT:
            edit_x(game, false);
            break;
        case KEY_UP:
            edit_y(game, true);
            break;
        case KEY_DOWN:
            edit_y(game, false);
            break;
    }
    return 0;
}
