/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** ues
*/
#include <stdlib.h>
#include "../../include/my.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    int i = 0;

    while (i < n - 1 && str1[i] == str2[i] && str1[i] != '\0'
        && str2[i] != '\0') {
        i++;
    }
    if (str1[i] != str2[i])
        return (str1[i] - str2[i]);
    return (0);
}

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return (-1);
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    if (str1[i] != '\0' && str2[i] != '\0' && str1[i] != str2[i])
        return (str1[i] - str2[i]);
    return (0);
}