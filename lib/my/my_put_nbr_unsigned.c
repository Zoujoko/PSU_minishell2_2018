/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** il sert a put un number (baptiste)
*/
#include "../../include/my.h"

int my_put_nbr_u(unsigned int nb)
{
    unsigned int get_mod;

    if (nb >= 10) {
        get_mod = (nb % 10);
        nb = (nb - get_mod) / 10;
        my_put_nbr_u(nb);
        my_putchar(48 + get_mod);
    }
    else
        my_putchar(48 + nb % 10);

}

unsigned int negative_u(int nb)
{
    unsigned int limit = 4294967295;
    nb *= -1;
    nb = limit - nb;
    nb = nb + 1;
    my_put_nbr_u(nb);
}

int my_put_nbr_unsigned(int nb)
{
    if (nb < 0)
        negative_u(nb);
    if (nb >= 0)
        my_put_nbr_u(nb);
}
