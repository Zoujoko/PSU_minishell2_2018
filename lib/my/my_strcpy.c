/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while ((src[a]) != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
