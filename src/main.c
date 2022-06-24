/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** main
*/

#include "sokoban.h"

static int sokoban(map_t *map, player_t *player)
{
    int key;
    int value = 0;

    refresh();
    while (1) {
        clear();
        for (int i = 0; map->map[i]; printw("%s", map->map[i]), i++);
        check_player_pos(map, player);
        key = getch();
        handle_key(map, key);
        move_player(map, player, key);
        replace_o(map);
        if (check_win(map) == 0) break;
        if (check_loose(map) == 0) {
            value = 1;
            break;
        }
        refresh();
    }
    return value;
}

static int init_sokoban(map_t *map, player_t *player)
{
    int ch;
    int value = 0;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    value = sokoban(map, player);
    endwin();
    return value;
}

static int init_prog(int argc, char **argv)
{
    player_t *player = NULL;
    map_t *map = NULL;
    char *str = NULL;
    int nb = 0;
    int value = 0;

    if ((str = get_map(argv)) == NULL)
        return 84;
    if ((nb = check_map(str)) == -1)
        return 84;
    map = (map_t *)malloc(sizeof(map_t));
    if ((map->map = convert_in_2d_array(str)) == NULL)
        return 84;
    map->backup_map = convert_in_2d_array(str);
    free(str);
    player = (player_t *)malloc(sizeof(player_t));
    value = init_sokoban(map, player);
    free(player);
    free(map);
    return value;
}

int main(int argc, char **argv)
{
    int value = 0;

    if (argc != 2) {
        my_putstr("Error: wrong argument. Try './my_sokoban map.txt'\n");
        return 84;
    }
    value = init_prog(argc, argv);
    return value;
}
