/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** duplicate a string
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}