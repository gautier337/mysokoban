/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** putstr
*/

int my_putchar(char c);

int my_putstr (char const *str)
{
    int i = 0;

    if (!str)
        return -1;
    while (str[i] != '\0') {
        if (my_putchar(str[i]) == -1)
            return -1;
        i++;
    }
    return 0;
}
