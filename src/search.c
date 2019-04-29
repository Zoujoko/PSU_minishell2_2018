/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** search
*/
#include <stdbool.h>
#include <unistd.h>
#include "minishell.h"

char *which_quest(char *quest)
{
    char current[256];

    if (my_strcmp(quest, "HOME") == 0)
        return ("/");
    if (my_strcmp(quest, "PATH") == 0)
        return (SAVE_PATH);
    if (my_strcmp(quest, "PWD") == 0 || my_strcmp(quest, "OLDPWD") == 0) {
        if (getcwd(current, 256) == NULL)
            exit(0);
        else
            return (getcwd(current, sizeof(current)));
    }
    return (NULL);
}

int     search_env(shell_t *mysh, char *quest)
{
    bool suceed = 0;

    for (int i = 0; mysh->envp[i] != NULL; i++) {
        if (mysh->envp[i] == NULL)
            continue;
        if (my_strncmp(mysh->envp[i], quest, my_strlen(quest)) == 0)
            suceed = 1;
    }
    if (suceed == 0) {
        mysh->envp = env_realloc(mysh, quest,  which_quest(quest));
        return (1);
    }
    return (0);
}