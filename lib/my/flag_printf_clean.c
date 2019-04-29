/*
** EPITECH PROJECT, 2018
** all flag for my_printformat
** File description:
** yes yes
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../include/my.h"

int nintendo_switch(char flag, va_list param)
{
    switch (flag) {
    case 'd':
        my_put_nbr(va_arg(param, int));
        break;
    case 'i':
        my_put_nbr(va_arg(param, int));
        break;
    case 'c':
        my_putchar(va_arg(param, int));
        break;
    case 's':
        my_putstr(va_arg(param, char *));
        break;
    default:
        nintendo_switch2(flag, param);
        break;
    }
    return (0);
}

int nintendo_switch2(char flag, va_list param)
{
    switch (flag) {
    case 'u':
        my_put_nbr_unsigned(va_arg(param , int));
        break;
    case 'x':
        my_put_nbr_hexa_x(va_arg(param, int));
        break;
    case 'X':
        my_put_nbr_hexa_x_caps(va_arg(param, int));
        break;
    case 'o':
        my_put_nbr_octal(va_arg(param, int));
        break;
    default:
        nintendo_switch3(flag, param);
        break;
    }
    return (0);
}

int nintendo_switch3(char flag, va_list param)
{
    switch (flag) {
    case 'p':
        my_put_pointer(va_arg(param, int));
        break;
    case 'b':
        my_put_nbr_bin(va_arg(param, int));
        break;
    case 'S':
        my_put_s_caps(va_arg(param, char *));
        break;
    case '%':
        my_putchar(flag);
        break;
    }
}
