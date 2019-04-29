/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    char s;

    while (str[a] != '\0') {
        a++;
        }
    a--;
    while (a > b)  {
        s = str[a];
        str[a] = str[b];
        str[b] = s;
        b++;
        a--;
    }
    return (str);
}
