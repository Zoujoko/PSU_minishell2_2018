/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** yes
*/
#include <signal.h>
#include "minishell.h"

int get_command(shell_t *mysh)
{
    int i = 0;
    size_t bufsize = 0;

    mysh->buffer = NULL;
    if (isatty(0) == 1)
        my_printf("\033[31m[lyoann@localhost%s]$ \033[00m", mysh->actual);
    if (getline(&mysh->buffer, &bufsize, stdin) == -1) {
        if (isatty(0) == 1)
            my_putchar('\n');
        exit(mysh->status);
    }
    for (; mysh->buffer[i] != '\n'; i++){
        if (mysh->buffer[i] == ';')
            mysh->howmanys++;
        else if (mysh->buffer[i] == '|')
            mysh->pipes++;
    }
    mysh->buffer[i] = '\0';
    return (0);
}

void exit_command(shell_t *mysh)
{
    my_printf("exit\n");
    exit(mysh->status);
}

void adding_oldpwd(shell_t *mysh)
{
    int i = 0;
    int j = 0;

    mysh->command = malloc(sizeof(char *) * (4));
    mysh->command[1] = "OLDPWD";
    search_env(mysh, "PWD");
    for (; my_strncmp(mysh->envp[i], "PWD", 3) != 0; i++);
    mysh->command[2] = my_strdup(mysh->envp[i] + 4);
    mysh->envp = env_realloc(mysh, "OLDPWD", mysh->command[2]);
    for (i = 0; my_strncmp(mysh->envp[i], "OLDPWD", 6) != 0; i++);
    j = my_strlen(mysh->envp[i]);
    for (; mysh->envp[i][j] != '/'; j--);
    mysh->envp[i][j] = '\0';
}

void which_command(shell_t *mysh)
{
    int i = 0;
    char save;
    int j = 0;

    get_command(mysh);
    for (; mysh->howmanys > 0; mysh->howmanys--) {
        if (mysh->howmanys == 0)
            return;
        for (; mysh->buffer[i] != ';' && mysh->buffer[i] != '\0'; i++);
        save = mysh->buffer[i];
        mysh->buffer[i] = '\0';
        mysh->command = get_cleaned(mysh->buffer + j);
        if (find_redirections(mysh) == 0 && test_buffer(mysh) == 0)
            prompt(mysh);
        mysh->buffer[i] = save;
        i++;
        j = i;
        restore_fd(mysh);
    }
}

int main(int argc, char **argv, char **envp)
{
    shell_t *mysh = malloc(sizeof(shell_t));

    if (argc != 1) {
        my_put_error("You have to run the mysh alone\n");
        return (84);
    }
    (void)argv;
    mysh->envp = envp;
    mysh->saves[0] = dup(STDIN_FILENO);
    mysh->saves[1] = dup(STDOUT_FILENO);
    adding_oldpwd(mysh);
    while (1) {
        mysh->pipes = 0;
        mysh->howmanys = 1;
        getting_actual_dir_name(mysh);
        which_command(mysh);
    }
    return (0);
}
