/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** my_strncpy
*/

#include "sokoban.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i != n; i++) {
        dest[i] = src[i];
        if (i == n && src[i] == '\0')
            return 0;
    }
    return dest;
}
