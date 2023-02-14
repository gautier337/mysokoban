/*
** EPITECH PROJECT, 2022
** display_map
** File description:
** display_map_use
*/

#include "header.h"

int display_map(char **map)
{
    refresh();
    if (!map)
        return 84;
    for (int i = 0; map[i] != NULL; i++)
        printw(map[i]);
    refresh();
    return 0;
}
