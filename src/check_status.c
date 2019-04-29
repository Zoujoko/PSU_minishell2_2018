/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** check_status
*/

#include "minishell.h"
#include <signal.h>
#include <string.h>

void check_status(shell_t *mysh, int status)
{
    if (WIFEXITED(status)) {
        mysh->status = (WEXITSTATUS(status));
        return;
    }
    if (WIFSIGNALED(status)) {
        mysh->status = status;
        if (WTERMSIG(status) == 8) {
            my_put_error("Floating Exception\n");
            return;
        }
        my_put_error(strsignal(WTERMSIG(status)));
        my_put_error("\n");
    }
}

void execution_mistake(shell_t *mysh)
{
    if (errno == ENOEXEC) {
        my_put_error(mysh->command[0]);
        my_put_error(": Exec format error. Wrong Architecture.\n");
        exit(errno);
    }
    my_put_error(mysh->command[0]);
    my_put_error(": ");
    my_put_error(strerror(errno));
    my_put_error(".\n");
    exit(errno);
}

void restore_fd(shell_t *mysh)
{
    dup2(mysh->saves[0], STDIN_FILENO);
    dup2(mysh->saves[1], STDOUT_FILENO);
}
