/*
** EPITECH PROJECT, 2022
** draw_text
** File description:
** my_runner
*/

#include "header.h"

char *my_strcat(char *src, char *dest)
{
    int len_src = my_strlen(src);
    int i = 0;
    char *tmp = src;
    char *new = malloc(my_strlen(dest) + my_strlen(src) + 1);

    if (!tmp || !new || !src || !dest)
        return NULL;
    for (int x = 0; x < len_src; x++)
        new[x] = tmp[x];
    while (dest[i] != '\0') {
        new[len_src + i] = dest[i];
        i++;
    }
    new[len_src + i] = '\0';
    return new;
}
