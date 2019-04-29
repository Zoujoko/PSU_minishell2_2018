/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec
*/

#include "minishell.h"

void my_exec(shell_t *mysh, int k)
{
    execve(mysh->path[k], mysh->command, mysh->envp);
    execution_mistake(mysh);
}