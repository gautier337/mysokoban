/*
** EPITECH PROJECT, 2022
** get_max_cols
** File description:
** get_max_cols
*/

#include "header.h"

int get_max_cols(int *list, char const *filepath)
{
    int tmp = 0;
    int lenght = get_lines(filepath);

    if (!list)
        return -1;
    for (int i = 0; i < lenght; i++)
        if (list[i] > tmp)
            tmp = list[i];
    return tmp;
}
