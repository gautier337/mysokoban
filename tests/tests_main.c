/*
** EPITECH PROJECT, 2022
** criterion test
** File description:
** minishell
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"

Test(my_strcmp, test_compare)
{
    int return_number = my_strcmp("salut", "salut");

    cr_assert_eq(1, return_number);
}

Test(my_strlen, test_strlen)
{
    int lenght_strlen = my_strlen("salut");

    cr_assert_eq(5, lenght_strlen);
}

Test(my_strcat, test_strcat)
{
    char *new_str = my_strcat("salut", "ok");

    cr_assert_str_eq("salutok", new_str);
}
