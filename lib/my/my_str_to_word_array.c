/*
** EPITECH PROJECT, 2018
** test
** File description:
** yes
*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int my_strlen_delim(char *str, char delim, int i)
{
    int line = 0;

    while (str[i] != delim && str[i] != '\0') {
            i++;
            line++;
    }
    return (line);
}

int get_lines(char *str, char delim)
{
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        if (str[i] == delim)
            line++;
        i++;
    }
    line++;
    return (line);
}

char **my_str_to_word_array(char *str, char delim)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **map = malloc(sizeof(char *) * (get_lines(str, delim) + 1));

    map[j] = malloc(sizeof(char) * (my_strlen_delim(str, delim, i)) + 1);
    while (j < get_lines(str, delim)) {
        while (str[i] != delim && str[i] != '\0') {
            map[j][k] = str[i];
            k++;
            i++;
        }
        i++;
        map[j][k] = '\0';
        k = 0;
        j++;
        map[j] = malloc(sizeof(char) * (my_strlen_delim(str, delim, i)) + 1);
    }
    map[j] = NULL;
    return (map);
}