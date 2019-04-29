/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** il sert a put un number (baptiste)
*/
#include "../../include/my.h"

int my_put_nbr_b(unsigned int nb)
{
    unsigned int get_mod;

    if (nb >= 2)
    {
        get_mod = (nb % 2);
        nb = (nb - get_mod) / 2;
        my_put_nbr_b(nb);
        my_putchar(48 + get_mod);
    }
    else
        my_putchar(48 + nb % 2);

}

unsigned int negative_b(int nb)
{
    unsigned int limit = 4294967295;
    nb *= -1;
    nb = limit - nb;
    nb = nb + 1;
    my_put_nbr_b(nb);
}

int my_put_nbr_bin(int nb)
{
    if (nb < 0)
        negative_b(nb);
    if (nb >= 0)
        my_put_nbr_b(nb);
}
