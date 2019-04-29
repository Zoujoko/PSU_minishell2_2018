/*
** EPITECH PROJECT, 2019
** cd
** File description:
** yes
*/

#include "minishell.h"

void cd_one_arg(shell_t *mysh)
{
    int j = 0;
    int retchdir = 0;

    search_env(mysh, "OLDPWD=");
    search_env(mysh, "PWD");
    if (my_strcmp(mysh->command[1], "-") == 0) {
        for (; my_strncmp(mysh->envp[j], "OLDPWD=", 7) != 0; j++);
        chdir(mysh->envp[j] + 7);
        update_env_minus(mysh);
    }
    else {
        retchdir = chdir(mysh->command[1]);
    if (retchdir == -1) {
        my_printf("%s: ", mysh->command[1]);
        my_printf("%s.\n", strerror(errno));
    }
    update_env_one_arg(mysh);
    }
}

void getting_actual_dir_name(shell_t *mysh)
{
    int i = 0;
    char current[256];
    char *dirname = getcwd(current, sizeof(current));

    i = my_strlen(dirname + 4);
    for (; dirname[i] != '/'; i--);
    mysh->actual = my_strdup(dirname + i + 1);
}

int cd_command(shell_t *mysh)
{
    int i = 0;
    int j = 0;

    for (; mysh->command[i] != NULL; i++);
    if (i == 1) {
        search_env(mysh, "HOME");
        for (; my_strncmp(mysh->envp[j], "HOME=", 5) != 0; j++);
        chdir(mysh->envp[j] + 5);
        update_env_no_arg(mysh);
    }
    else if (i == 2) {
        cd_one_arg(mysh);
    }
    else {
        my_printf("cd: Too any arguments");
    }
    return (0);
}