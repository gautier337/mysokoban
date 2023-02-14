/*
** EPITECH PROJECT, 2022
** set_game
** File description:
** set_game
*/

#include "header.h"

int game(game_t *game, int ch)
{
    get_control(ch, game);
    clear();
    for (int i = 0; game->basket[i] != NULL; i++)
        if (game->map[game->basket[i]->y][game->basket[i]->x] != 'P' &&
            game->map[game->basket[i]->y][game->basket[i]->x] != 'X')
            game->map[game->basket[i]->y][game->basket[i]->x] = 'O';
    display_map(game->map);
}

void settings_window(void)
{
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_WHITE);
    raw();
    noecho();
    keypad(stdscr, TRUE);
}

int check_wsize(game_t *game, char const *filepath)
{
    int row = 0;
    int col = 0;
    int map_rows = get_lines(filepath);
    int max_cols = get_max_cols(get_list_bytes(filepath), filepath);

    if (!game)
        return -1;
    getmaxyx(stdscr, row, col);
    if (row < map_rows || col < max_cols)
        clear();
    while (row < map_rows || col < max_cols) {
        getmaxyx(stdscr, row, col);
        mvprintw(row / 2, (col - my_strlen("SIZE TOO LITTLE"))
            / 2, "SIZE TOO LITTLE");
        refresh();
    }
    return 0;
}

int game_playing(game_t *games, char **argv)
{
    int ch = 0;

    if ((ch = getch())
        == 'q')
        return 1;
    check_space(ch, games, argv);
    clear();
    game(games, ch);
    if (!(games->map))
        printw("error");
    refresh();
    check_status(games);
    return 0;
}
