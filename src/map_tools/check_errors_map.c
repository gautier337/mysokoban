/*
** EPITECH PROJECT, 2022
** check_error map
** File description:
** check_errors_map
*/

#include "header.h"

int check_ascii_map(char *map)
{
    if (!map)
        return 84;
    for (int y = 0; map[y] != '\0'; y++)
        if (!(map[y] == ' ' || map[y] == '#' || map[y] == 'X'
            || map[y] == 'O' || map[y] == 'P' || map[y] == '\n'))
            return 84;
    return 0;
}

int check_map_errors(char **map)
{
    if (!map)
        return -1;
    for (int i = 0; map[i] != NULL; i++)
        if (check_ascii_map(map[i]) == 84) {
            free(map);
            exit(84);
        }
    return 0;
}
