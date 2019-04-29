/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** il sert a put un number (baptiste)
*/
#include "../../include/my.h"

int my_put_nbr(int nbr)
{
    int get_mod;

    if (nbr < 0) {
        my_putchar('-');
        nbr *= (-1);
    }
    if (nbr >= 0) {
        if (nbr >= 10) {
            get_mod = (nbr % 10);
            nbr = (nbr - get_mod) / 10;
            my_put_nbr(nbr);
            my_putchar(48 + get_mod);
        }
        else
            my_putchar(48 + nbr % 10);
    }
}
