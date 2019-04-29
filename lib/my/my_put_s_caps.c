/*
** EPITECH PROJECT, 2018
** %S lib
** File description:
** yes
*/

#include "../../include/my.h"

int my_put_nbr_caps_s(int nb)
{
    int get_mod;

    if (nb >= 8)
    {
        get_mod = (nb % 8);
        nb = (nb - get_mod) / 8;
        my_put_nbr_caps_s(nb);
        my_putchar(48 + get_mod);
    }
    else
        my_putchar(48 + nb % 8);

}

int put_zero(unsigned int octal)
{
    if (octal <= 7) {
        my_putchar('0');
        my_putchar('0');
    }
    if (octal <= 77 && octal >= 7)
        my_putchar('0');
}

void my_put_s_caps(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 32 && str [i] <= 127) {
            my_putchar(str[i]);
            i++;
        }
        else {
            my_putchar('\\');
            put_zero(str[i]);
            my_put_nbr_caps_s(str[i]);
            i++;
        }
    }
}
