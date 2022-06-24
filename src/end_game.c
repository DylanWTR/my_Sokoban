/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** end_game
*/

#include "sokoban.h"

static int check_stuck(map_t *map, int i, int j)
{
    if (map->map[i][j + 1] == '#' && (map->map[i - 1][j] == '#' || map->map[i + 1][j] == '#'))
        return 1;
    if (map->map[i][j - 1] == '#' && (map->map[i - 1][j] == '#' || map->map[i + 1][j] == '#'))
        return 1;
    if (map->map[i + 1][j] == '#' && (map->map[i][j - 1] == '#' || map->map[i][j + 1] == '#'))
        return 1;
    if (map->map[i - 1][j] == '#' && (map->map[i][j - 1] == '#' || map->map[i][j + 1] == '#'))
        return 1;
    return 0;
}

int check_win(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++)
        for (int j = 0; map->map[i][j] != '\0'; j++)
            if (map->map[i][j] == 'X' && map->backup_map[i][j] != 'O')
                return 1;
    return 0;
}

int check_loose(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++)
        for (int j = 0; map->map[i][j] != '\0'; j++)
            if (map->map[i][j] == 'X')
                if (check_stuck(map, i, j) == 0)
                    return 1;
    return 0;
}
