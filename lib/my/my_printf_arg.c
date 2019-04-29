/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** yes
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../include/my.h"

int my_printf(char *str, ...)
{
    int disp_c = 0;
    va_list param;
    int str_c = 0;
    char flag;

    va_start(param, str);
    while (str[str_c] != '\0') {
        if (str[str_c] == '%') {
            flag = str[str_c + 1];
            nintendo_switch(flag, param);
            str_c++;
        }
        else
            my_putchar(str[str_c]);
        str_c++;
    }
    va_end(param);
}
