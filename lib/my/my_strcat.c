/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenates two strings
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int len1 = my_strlen(dest);
    int len2 = (my_strlen(src) + 1);
    char *both = malloc(sizeof(char) * (len1 + len2));

    for (int i = 0; dest[i] != '\0'; i++, a++)
        both[a] = dest[i];
    for (int i = 0; src[i] != '\0'; i++, a++)
        both[a] = src[i];
    both[a] = '\0';
    return (both);
}
