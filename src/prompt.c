/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** yes
*/
#include "minishell.h"
#include <signal.h>
#include <errno.h>

void get_pathed(shell_t *mysh)
{
    char *line_path;

    for (int k = 0; mysh->envp[k] != NULL; k++) {
        search_env(mysh, "PATH");
        if (my_strncmp(mysh->envp[k], "PATH=", 5) == 0) {
            line_path = my_strdup(mysh->envp[k]);
        }
    }
    mysh->path = my_str_to_word_array(line_path + 5, ':');
    free (line_path);
}

int testing_alone(shell_t *mysh)
{
    if (execve(mysh->command[0], mysh->command, mysh->envp) == 0)
        return (1);
    else
        return (0);
}

void testing_path(shell_t *mysh)
{
    int k = 0;
    int j = testing_alone(mysh);

    if (mysh->command[0] != NULL && j == 0) {
        mysh->path[k] = my_strcat(mysh->path[k], "/");
        mysh->path[k] = my_strcat(mysh->path[k], mysh->command[0]);
    }
    while (access(mysh->path[k], X_OK) == - 1 && mysh->path[k] != NULL) {
        k++;
        if (mysh->path[k] != NULL && j == 0) {
            mysh->path[k] = my_strcat(mysh->path[k], "/");
            mysh->path[k] = my_strcat(mysh->path[k], mysh->command[0]);
        }
    }
    if (((mysh->path[k] == NULL && check_inside_file(mysh) == 0))
        || ((mysh->command[0][1] == '\0') && (j == 0))) {
        my_printf("%s: Command not found.\n", mysh->command[0]);
    }
    else
        my_exec(mysh, k);
}

int test_buffer(shell_t *mysh)
{
    if (my_strcmp((mysh->command[0]), "cd") == 0) {
        cd_command(mysh);
        return (1);
    }
    if (my_strcmp((mysh->command[0]), "exit") == 0) {
        exit_command(mysh);
    }
    if (my_strcmp((mysh->command[0]), "setenv") == 0) {
        setenv_command(mysh);
        return (1);
    }
    if (my_strcmp((mysh->command[0]), "unsetenv") == 0) {
        unsetenv_command(mysh);
        return (1);
    }
    if (my_strcmp((mysh->command[0]), "env") == 0) {
        env_command(mysh);
        return (1);
    }
    return (0);
}

void prompt(shell_t *mysh)
{
    int stats = 0;

    if (my_strlen(mysh->command[0]) == 0)
        return;
    mysh->trident = 0;
    if (mysh->command[0] != NULL)
        mysh->trident = fork();
    get_pathed(mysh);
    if (mysh->trident == 0) {
        testing_path(mysh);
    }
    else {
        waitpid(mysh->trident, &stats, WUNTRACED | WCONTINUED);
        check_status(mysh, stats);
    }
}
