/*
** EPITECH PROJECT, 2019
** put error case
** File description:
** yes
*/
#include <unistd.h>

void char_error(char c)
{
    write(2, &c, 1);
}

void my_put_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        char_error(str[i]);
        i++;
    }
}
