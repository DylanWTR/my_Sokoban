/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** check_pos
*/

#include "sokoban.h"

static void player_pos(map_t *map, player_t *player, int row, int col)
{
    if (map->map[row][col] == 'P') {
        player->col = col;
        player->row = row;
    }
}

void check_player_pos(map_t *map, player_t *player)
{
    for (int row = 0; map->map[row] != NULL; row++)
        for (int col = 0; map->map[row][col] != '\0'; col++)
            player_pos(map, player, row, col);
}
