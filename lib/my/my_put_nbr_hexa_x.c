/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** il sert a put un number (baptiste)
*/
#include "../../include/my.h"

int my_put_nbr_x(unsigned int nb)
{
    unsigned int get_mod;
    char base[16] = "0123456789abcdef";
    int print;

    if (nb >= 16) {
        get_mod = (nb % 16);
        nb = (nb - get_mod) / 16;
        my_put_nbr_x(nb);
        print = get_mod;
        my_putchar(base[print]);
    }
    else {
        print = nb;
        my_putchar(base[print]);
    }
}

unsigned int negative_x(int nb)
{
    unsigned int limit = 4294967295;
    nb *= -1;
    nb = limit - nb;
    nb = nb + 1;
    my_put_nbr_x(nb);
}

int my_put_nbr_hexa_x(int nb)
{
    if (nb < 0)
        negative_x(nb);
    if (nb >= 0)
        my_put_nbr_x(nb);
}
