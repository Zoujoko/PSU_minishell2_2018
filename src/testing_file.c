/*
** EPITECH PROJECT, 2019
** testing file
** File description:
** yes
*/
#include "minishell.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int check_rights(struct stat *info, char *name, shell_t *mysh)
{
    char *param[2];

    if (my_strcmp(name, mysh->command[0] + 2) != 0)
        return (0);
    if (name[0] == '.')
        return (0);
    if (info->st_mode & S_IXUSR) {
        param[0] = name;
        param[1] = NULL;
        execve(name, param, mysh->envp);
        return (1);
    }
    return (0);
}

int check_inside_file(shell_t *mysh)
{
    DIR *openz = opendir(".");
    struct dirent *readz;
    struct stat get_stat;

    if (openz == NULL)
        return (0);
    while ((readz = readdir(openz)) != NULL) {
        stat(readz->d_name, &get_stat);
        if (check_rights(&get_stat, readz->d_name, mysh) == 1)
            return (1);
    }
    return (0);
}