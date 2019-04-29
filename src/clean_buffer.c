/*
** EPITECH PROJECT, 2019
** clean buffer
** File description:
** yes
*/
#include "minishell.h"

int my_strlen_toclean(char *str, char delim, int i)
{
    int line = 0;

    while (str[i] != delim && str[i] != '\0') {
            i++;
            line++;
    }
    return (line);
}

char **str_to_clean(char *buffer, int lines, char limit)
{
    char **clean = malloc(sizeof(char *) * (lines + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    while (j < lines) {
        for (; buffer[i] == ' ' || buffer[i] == limit; i++);
        clean[j] = malloc(sizeof(char) * (my_strlen_toclean(buffer, ' ',
            i) + 1));
        for (k = 0; buffer[i] != limit && buffer[i] != '\0'; i++, k++) {
            clean[j][k] = buffer[i];
        }
        i++;
        clean[j][k] = '\0';
        j++;
    }
    clean[j] = NULL;
    return (clean);
}

char **get_cleaned(char *buffer, char limit)
{
    int i = 0;
    int j = 0;

    for (int k = 0; buffer[k] != '\0';) {
        if (buffer[k] == '\t') {
            buffer[k] = ' ';
            k++;
        }
        else
            k++;
    }
    while (buffer[i] != '\0') {
        for (; buffer[i] < 33 && buffer[i] != '\0'; i++);
        if (buffer[i] != '\0')
            j++;
        for (; buffer[i] > 32 && buffer[i] != '\0'; i++);
    }
    return (str_to_clean(buffer, j));
}
