/*
** EPITECH PROJECT, 2022
** load_map
** File description:
** load_map
*/

#include "header.h"

int get_lines(char const *filepath)
{
    struct stat t;
    int size = 0;
    int fd = open(filepath, O_RDONLY);
    char *buff = NULL;
    int nbr = 0;

    if (fd == -1)
        return -1;
    stat(filepath, &t);
    buff = malloc(t.st_size);
    read(fd, buff, t.st_size);
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            nbr++;
    return nbr;
}

int *algo(char *buff, int *list)
{
    int yindex = 0;
    int xindex = 0;

    for (int i = 0; buff[i] != '\0';) {
        if (buff[i] == '\n') {
            list[yindex] = xindex;
            yindex++;
            xindex = 0;
            i++;
        }
        xindex++;
        i++;
    }
    return list;
}

int *get_list_bytes(char const *filepath)
{
    struct stat t;
    int size = 0;
    int fd = open(filepath, O_RDONLY);
    char *buff = NULL;
    int *list = malloc(sizeof(int) * get_lines(filepath));

    if (fd == -1)
        return NULL;
    stat(filepath, &t);
    buff = malloc(t.st_size);
    read(fd, buff, t.st_size);
    return algo(buff, list);
}

char **map_from_file(char const *filepath)
{
    struct stat t;
    int size = 0;
    int fd = open(filepath, O_RDONLY);
    int rows = get_lines(filepath);
    char **map = malloc(sizeof(char *) * rows + 1);
    int *list;

    if (fd == -1)
        return NULL;
    list = get_list_bytes(filepath);
    for (int i = 0; i < rows; i++) {
        map[i] = malloc(list[i] + 2);
        read(fd, map[i], list[i] + 1);
    }
    close(fd);
    if (check_map_errors(map) == 84)
        return NULL;
    return map;
}
