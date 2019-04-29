/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get a number
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != '\0')
        i = 1;
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
        n += str[i] - 48;
        n *= 10;
        }
        i++;
    }
    if (str[0] == '-') {
        return (-1 * n);
    }
    n /= 10;
    return (n);
}