/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** my_strcpy
*/

#include "sokoban.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; dest[i] != '\0'; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            return 0;
    }
    return dest;
}
