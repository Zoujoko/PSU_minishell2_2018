/*
** EPITECH PROJECT, 2018
** put pointer adress
** File description:
** yes
*/
#include <stdio.h>
#include "../../include/my.h"

int  my_put_pointer(int nb)
{
    my_putstr("0x");
    my_put_nbr_hexa_x(nb);
}
