/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** move
*/

#include "sokoban.h"

void move_right(map_t *map, player_t *player)
{
    if (map->map[player->row][player->col + 1] == '#')
        return;
    if (map->map[player->row][player->col + 1] == 'X' &&
        map->map[player->row][player->col + 2] == '#')
        return;
    if (map->map[player->row][player->col + 1] == 'X' &&
        map->map[player->row][player->col + 2] == 'X')
        return;
    if (map->map[player->row][player->col + 1] == 'X')
        map->map[player->row][player->col + 2] = 'X';
    map->map[player->row][player->col += 1] = 'P';
    map->map[player->row][player->col - 1] = ' ';
}

void move_left(map_t *map, player_t *player)
{
    if (map->map[player->row][player->col - 1] == '#')
        return;
    if (map->map[player->row][player->col - 1] == 'X' &&
        map->map[player->row][player->col - 2] == '#')
        return;
    if (map->map[player->row][player->col - 1] == 'X' &&
        map->map[player->row][player->col - 2] == 'X')
        return;
    if (map->map[player->row][player->col - 1] == 'X')
        map->map[player->row][player->col - 2] = 'X';
    map->map[player->row][player->col -= 1] = 'P';
    map->map[player->row][player->col + 1] = ' ';
}

void move_up(map_t *map, player_t *player)
{
    if (map->map[player->row - 1][player->col] == '#')
        return;
    if (map->map[player->row - 1][player->col] == 'X' &&
        map->map[player->row - 2][player->col] == '#')
        return;
    if (map->map[player->row - 1][player->col] == 'X' &&
        map->map[player->row - 2][player->col] == 'X')
        return;
    if (map->map[player->row - 1][player->col] == 'X')
        map->map[player->row - 2][player->col] = 'X';
    map->map[player->row -= 1][player->col] = 'P';
    map->map[player->row + 1][player->col] = ' ';
}

void move_down(map_t *map, player_t *player)
{
    if (map->map[player->row + 1][player->col] == '#')
        return;
    if (map->map[player->row + 1][player->col] == 'X' &&
        map->map[player->row + 2][player->col] == '#')
        return;
    if (map->map[player->row + 1][player->col] == 'X' &&
        map->map[player->row + 2][player->col] == 'X')
        return;
    if (map->map[player->row + 1][player->col] == 'X')
        map->map[player->row + 2][player->col] = 'X';
    map->map[player->row += 1][player->col] = 'P';
    map->map[player->row - 1][player->col] = ' ';
}

void move_player(map_t *map, player_t *player, int key)
{
    if (key == KEY_RIGHT)
        move_right(map, player);
    if (key == KEY_LEFT)
        move_left(map, player);
    if (key == KEY_UP)
        move_up(map, player);
    if (key == KEY_DOWN)
        move_down(map, player);
}
