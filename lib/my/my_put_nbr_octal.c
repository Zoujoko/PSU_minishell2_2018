/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** il sert a put un number (baptiste)
*/
#include "../../include/my.h"

int my_put_nbr_o(unsigned int nb)
{
    unsigned int get_mod;

    if (nb >= 8) {
        get_mod = (nb % 8);
        nb = (nb - get_mod) / 8;
        my_put_nbr_o(nb);
        my_putchar(48 + get_mod);
    }
    else
        my_putchar(48 + nb % 8);
}

unsigned int negative_o(int nb)
{
    unsigned int limit = 4294967295;
    nb *= -1;
    nb = limit - nb;
    nb = nb + 1;
    my_put_nbr_o(nb);
}

int my_put_nbr_octal(int nb)
{
    if (nb < 0)
        negative_o(nb);
    if (nb >= 0)
        my_put_nbr_o(nb);
}
