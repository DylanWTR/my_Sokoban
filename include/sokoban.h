/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <ncurses.h>

typedef struct map {
    char **map;
    char **backup_map;
}
map_t;

typedef struct player_coordinates {
    int col;
    int row;
}
player_t;

/* LIBRARY */
int my_putstr(char const *str);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);

/* CREATE_MAP */
char **convert_in_2d_array(char *str);
char *get_map(char **argv);
int check_map(char *str);

/* CHECK POS */
void check_player_pos(map_t *map, player_t *player);

/* MOVE PLAYER AND CHECK COLLISIONS */
void move_right(map_t *map, player_t *player);
void move_left(map_t *map, player_t *player);
void move_up(map_t *map, player_t *player);
void move_down(map_t *map, player_t *player);
void move_player(map_t *map, player_t *player, int key);

/* END CHECKERS */
int check_loose(map_t *map);
int check_win(map_t *map);

/* MISCELLANEOUS */
void handle_key(map_t *map, int key);
void replace_o(map_t *map);

#endif /* !SOKOBAN_H_ */
