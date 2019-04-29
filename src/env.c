/*
** EPITECH PROJECT, 2019
** env yes
** File description:
** yes
*/

#include "minishell.h"

int find_size(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}

char **env_realloc_half(shell_t *mysh, char *new)
{
    char **news = malloc(sizeof(char *) * (find_size(mysh->envp) + 1));
    int i = 0;
    int j = 0;
    char *setenv = my_strcat(new, "=");
    int k = 0;

    for (; mysh->envp[i] != NULL; i++, j++) {
        if (my_strncmp(mysh->envp[i], setenv, my_strlen(setenv)) == 0)
            k = j;
        news[j] = my_strdup(mysh->envp[i]);
    }
    if (k != 0)
        news[k] = setenv;
    else {
        news[j] = setenv;
        news[j + 1] = NULL;
    }
    return (news);
}

char **env_realloc(shell_t *mysh, char *newenv, char *value)
{
    char **news = malloc(sizeof(char *) * (find_size(mysh->envp) + 1));
    int i = 0;
    int j = 0;
    char *setenv = my_strcat(newenv, "=");
    int k = 0;

    if (newenv == NULL || value == NULL || my_strlen(value) == 0)
        exit(mysh->status);
    for (; mysh->envp[i] != NULL; i++, j++) {
        if (my_strncmp(mysh->envp[i], setenv, my_strlen(setenv)) == 0)
            k = j;
        news[j] = my_strdup(mysh->envp[i]);
    }
    if (k != 0)
        news[k] = my_strcat(setenv, value);
    else {
        news[j] = my_strcat(setenv, value);
        news[j + 1] = NULL;
    }
    return (news);
}

void env_command(shell_t *mysh)
{
    for (int i = 0; mysh->envp[i] != NULL; i++)
        my_printf("%s\n", mysh->envp[i]);
}

int setenv_command(shell_t *mysh)
{
    int i = 0;

    for (; mysh->command[i] != NULL; i++);
    if (i > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    }
    if (i > 1 && my_isalpha(mysh->command[1]) == 84) {
        my_printf("setenv: Variable name must contain alphanumeric");
        my_printf(" characters.\n");
        return (1);
    }
    if (i == 1)
        env_command(mysh);
    else if (i == 2)
        mysh->envp = env_realloc_half(mysh, mysh->command[1]);
    else
        mysh->envp = env_realloc(mysh, mysh->command[1], mysh->command[2]);
    return (0);
}
