/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** yes
*/

#include <stdbool.h>
#include "minishell.h"

int my_isalpha(char *newenv)
{
    int i = 0;
    bool test = 0;

    if (newenv == NULL)
        return (0);
    for (; newenv[i] != '\0'; i++) {
        if (newenv[i] >= 'A' && newenv[i] <= 'Z')
            test = 1;
        if (newenv[i] >= 'a' && newenv[i] <= 'z')
            test = 1;
        if (newenv[i] >= '0' && newenv[i] <= '9')
            test = 1;
        if (test == 0)
            return (84);
        test = 0;
    }
    return (0);
}

char **unsetenv_realloc(shell_t *mysh, char *test)
{
    char **news = malloc(sizeof(char *) * (find_size(mysh->envp) + 1));
    int i = 0;
    int j = 0;

    for (; mysh->envp[i] != NULL;) {
        if (my_strncmp(mysh->envp[i], test, my_strlen(test)) == 0) {
            i++;
        }
        else {
            news[j] = my_strdup(mysh->envp[i]);
            i++;
            j++;
        }
    }
    return (news);
}

int unsetenv_command(shell_t *mysh)
{
    int i = 0;

    for (; mysh->command[i] != NULL; i++);
    if (i == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    }
    for (int k = 1; mysh->command[k] != NULL; k++)
        mysh->envp = unsetenv_realloc(mysh, mysh->command[k]);
    return (0);
}
