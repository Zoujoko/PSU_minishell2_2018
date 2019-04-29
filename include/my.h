/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** yes
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#pragma once

int my_getnbr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_put_nbr_hexa_x(int nb);
unsigned int negative_x(int nb);
int my_put_nbr_x(unsigned int nb);
int my_put_nbr_hexa_x_caps(int nb);
int my_put_nbr_x_caps(unsigned int nb);
unsigned int negative_x_caps(int nb);
int my_put_nbr_octal(int nb);
int my_put_nbr_o(unsigned int nb);
unsigned int negative_o(int nb);
int my_put_nbr_unsigned(int nb);
unsigned int negative_u(int nb);
int my_put_nbr_u(unsigned int nb);
int my_put_nbr_b(unsigned int nb);
unsigned int negative_b(int nb);
int my_put_nbr_bin(int nb);
int my_put_pointer(int nb);
int nintendo_switch(char flag, va_list param);
int nintendo_switch2(char flag, va_list param);
int nintendo_switch3(char flag, va_list param);
int my_printf(char *str, ...);
int put_zero(unsigned int octal);
void my_put_s_caps(char const *str);
int my_put_nbr_caps_s(int nb);
char *my_strdup(char *str);
void my_put_error(char const *str);
char **my_str_to_word_array(char *str, char delim);
int my_strncmp(char const *str1, char const *str2, int n);
int my_strcmp(char const *str1, char const *str2);
