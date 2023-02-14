/*
** EPITECH PROJECT, 2022
** name_formatter
** File description:
** main
*/

#include "header.h"

int play(char **argv)
{
    game_t game_s;
    int ch = 0;

    if (init(&game_s, argv) == 84)
        return 84;
    settings_window();
    display_map(game_s.map);
    while (game_s.status == -1) {
        check_wsize(&game_s, argv[1]);
        if (game_playing(&game_s, argv) == 1)
            return 0;
    }
    return game_s.status;
}

int sokoban(int argc, char **argv)
{
    game_t game_s;
    int status = 0;

    if (!argv)
        return 84;
    if ((status = play(argv))
        == 84) {
        endwin();
        return 84;
    }
    endwin();
    return status;
}
