/*
** EPITECH PROJECT, 2022
** Unix_System_Programming
** File description:
** init_map
*/

#include "sokoban.h"

int check_map(char *str)
{
    int var = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '#' && str[i] != 'X' && str[i] != 'O' && str[i] != 'P')
            return -1;
    }
    return 0;
}

static int count_lines(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            counter++;
    return counter;
}

char *get_map(char **argv)
{
    int file;
    int buffer_size = 30000;
    char buffer[buffer_size];
    int len = 0;
    char *str = NULL;

    if ((file = open(argv[1], O_RDONLY)) == -1)
        return NULL;
    if (read(file, buffer, buffer_size) == -1)
        return NULL;
    if ((len = my_strlen(buffer)) != 0) {
        str = (char *)malloc(sizeof(char) * len + 1);
        str = my_strncpy(str, buffer, len);
        str[len] = '\0';
    }
    return str;
}

char **fill_2d_array(char **tab, char *str, int i, int n)
{
    tab[n] = (char *)malloc(sizeof(char) * i + 1);
    tab[n] = my_strncpy(tab[n], str, i);
    tab[n][i] = '\0';
    return tab;
}

char **convert_in_2d_array(char *str)
{
    char **tab = NULL;
    int lines_nbr = 0;
    int rows_nbr = 0;
    int n = 0;

    if ((lines_nbr = count_lines(str)) == 0)
        return NULL;
    if ((tab = (char **)malloc(sizeof(char *) * lines_nbr + 1)) == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            tab = fill_2d_array(tab, str, i, n);
            n++;
            str += i;
            i = 0;
        }
    }
    tab[n] = NULL;
    return tab;
}
