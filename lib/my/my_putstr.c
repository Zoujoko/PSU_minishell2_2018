/*
** EPITECH PROJECT, 2018
** my_putsr
** File description:
** Display 1 by 1 string's character
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}
