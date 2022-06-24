/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** misc
*/

#include "sokoban.h"

void handle_key(map_t *map, int key)
{
    if (key == 32)
        for (int i = 0; map->backup_map[i] != NULL; i++)
            map->map[i] = my_strcpy(map->map[i], map->backup_map[i]);
    if (key == 27) {
        endwin();
        exit(1);
    }
}

void replace_o_bis(map_t *map, int i, int j)
{
    if (map->backup_map[i][j] == 'O')
        if (map->map[i][j] == ' ')
            map->map[i][j] = 'O';
}

void replace_o(map_t *map)
{
    for (int i = 0; map->backup_map[i] != NULL; i++)
        for (int j = 0; map->backup_map[i][j] != '\0'; j++)
            replace_o_bis(map, i, j);
}
