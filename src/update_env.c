/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** update_env
*/

#include "minishell.h"

int update_env_no_arg(shell_t *mysh)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *temp;

    for (; my_strncmp(mysh->envp[i], "PWD=", 4) != 0; i++);
    temp = my_strdup(mysh->envp[i] + 4);
    for (; my_strncmp(mysh->envp[j], "OLDPWD=", 7) != 0
        && mysh->envp[j] != NULL; j++);
    if (mysh->envp[i] == NULL)
        return (1);
    mysh->envp[j] = NULL;
    mysh->envp[j] = my_strcat("OLDPWD=", temp);
    for (; my_strncmp(mysh->envp[k], "HOME=", 5) != 0; k++);
    mysh->envp[i] = my_strcat("PWD=", mysh->envp[k] + 5);
    return (0);
}

int update_env_minus(shell_t *mysh)
{
    char *temp;
    int j = 0;
    int i = 0;
    char *pwd;

    for (; my_strncmp(mysh->envp[i], "OLDPWD=", 7) != 0; i++);
    temp = my_strdup(mysh->envp[i] + 7);
    for (; my_strncmp(mysh->envp[j], "PWD=", 4) != 0; j++);
    pwd = my_strdup(mysh->envp[j] + 4);
    if (mysh->envp[i] == NULL)
        return (1);
    mysh->envp[j] = my_strcat("PWD=", temp);
    mysh->envp[i] = my_strcat("OLDPWD=", pwd);
    return (0);
}

int update_env_one_arg(shell_t *mysh)
{
    char *temp;
    int j = 0;
    int i = 0;

    for (; my_strncmp(mysh->envp[i], "PWD=", 4) != 0; i++);
    temp = my_strdup(mysh->envp[i] + 4);
    for (; my_strncmp(mysh->envp[j], "OLDPWD=", 7) != 0
        && mysh->envp[j] != NULL; j++);
    if (mysh->envp[i] == NULL)
        return (1);
    mysh->envp[j] = my_strdup("OLDPWD=");
    mysh->envp[j] = my_strcat(mysh->envp[j], temp);
    mysh->envp[i] = my_strdup("PWD=");
    mysh->envp[i] = my_strcat(mysh->envp[i],
        (getcwd(mysh->command[1], 256)));
    return (0);
}
