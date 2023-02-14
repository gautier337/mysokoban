/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** str_cmp
*/

#include "header.h"

int my_strcmp (char const *s1, char const *s2)
{
    int i = 0;
    int count;
    int value = 0;

    if (!s1 || !s2)
        return -1;
    while (s1[i] != '\0' && s2[i] != '\0') {
        count = s1[i] - s2[i];
        if (count < 0 || count > 0)
            return 0;
        else
            i++;
    }
    if (my_strlen(s1) > my_strlen(s2))
        return 0;
    else if (my_strlen(s1) < my_strlen(s2))
        return 0;
    return 1;
}
