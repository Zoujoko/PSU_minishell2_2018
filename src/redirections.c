/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** redirections
*/

#include "minishell.h"
#include <sys/types.h>
#include <fcntl.h>

void relead_exit(shell_t *mysh, int j)
{
    int fd = 0;
    char *filename = NULL;

    mysh->command[j] = '\0';
    filename = my_strdup(mysh->command[j + 1]);
    mysh->command[j + 1] = '\0';
    fd = open(filename, O_RDWR + O_CREAT + O_TRUNC, S_IRUSR + S_IWUSR +
        S_IRGRP + S_IWGRP + S_IROTH);
    get_pathed(mysh);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    mysh->trident = fork();
    if (mysh->trident == 0) {
        testing_path(mysh);
    }
    else
        wait(&mysh->status);
}

void relead_add_exit(shell_t *mysh, int j)
{
    int fd = 0;
    char *filename = NULL;

    mysh->command[j] = '\0';
    filename = my_strdup(mysh->command[j + 1]);
    mysh->command[j + 1] = '\0';
    fd = open(filename, O_RDWR + O_CREAT + O_APPEND, S_IRUSR + S_IWUSR +
        S_IRGRP + S_IWGRP + S_IROTH);
    get_pathed(mysh);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    mysh->trident = fork();
    if (mysh->trident == 0) {
        testing_path(mysh);
    }
    else
        wait(&mysh->status);
}

void relead_enter(shell_t *mysh, int j)
{
    int fd = 0;
    char *filename = NULL;

    mysh->command[j] = '\0';
    filename = my_strdup(mysh->command[j + 1]);
    mysh->command[j + 1] = '\0';
    fd = open(filename, O_RDWR + O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP +
        S_IWGRP + S_IROTH);
    get_pathed(mysh);
    dup2(fd, STDIN_FILENO);
    close(fd);
    mysh->trident = fork();
    if (mysh->trident == 0) {
        testing_path(mysh);
    }
    else
        wait(&mysh->status);
}

void relead_double_enter(shell_t *mysh, int j)
{
    int fd = 0;
    char *filename = NULL;

    mysh->command[j] = '\0';
    filename = my_strdup(mysh->command[j + 1]);
    mysh->command[j + 1] = '\0';
    fd = open(filename, O_RDWR + O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP +
        S_IWGRP + S_IROTH);
    get_pathed(mysh);
    dup2(fd, STDIN_FILENO);
    close(fd);
    mysh->trident = fork();
    if (mysh->trident == 0) {
        testing_path(mysh);
    }
    else
        wait(&mysh->status);
}

int find_redirections(shell_t *mysh)
{
    for (int j = 0; mysh->command[j + 1] != NULL; j++) {
        if (my_strcmp(mysh->command[j], ">") == 0) {
            relead_exit(mysh, j);
            return (1);
        }
        if (my_strcmp(mysh->command[j], ">>") == 0) {
            relead_add_exit(mysh, j);
            return (1);
        }
        if (my_strcmp(mysh->command[j], "<") == 0) {
            relead_enter(mysh, j);
            return (1);
        }
        if (my_strcmp(mysh->command[j], "<<") == 0) {
            relead_double_enter(mysh, j);
            return (1);
        }
    }
    return (0);
}
