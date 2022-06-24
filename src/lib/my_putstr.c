/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** my_putstr
*/

#include "sokoban.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        n = str[i];
        my_putchar(n);
    }
    return 0;
}
