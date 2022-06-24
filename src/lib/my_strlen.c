/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** my_strlen
*/

#include "sokoban.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
