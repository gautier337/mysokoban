/*
** EPITECH PROJECT, 2022
** main
** File description:
** mainfunction
*/

#include "header.h"

int helper(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map");
    my_putstr(", containing '#' for walls, \n");
    my_putstr("         'P' for the player, 'X' for boxes and 'O' for");
    my_putstr("storage locations.\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (!argv || argc != 2) {
        helper();
        return 84;
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return helper();
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        my_putstr("Invalid map path or map file.\n");
        return 84;
    }
    return sokoban(argc, argv);
}
