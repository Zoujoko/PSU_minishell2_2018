/*
** EPITECH PROJECT, 2018
** put_float
** File description:
** yes
*/
#include <stdio.h>
#include "../../include/my.h"

void my_put_float(double nb)
{
    int before_coma = nb;
    int after_coma = (nb - before_coma) * (1000000);

    my_put_nbr(before_coma);
    my_putchar('.');
    my_put_nbr(after_coma);
}
