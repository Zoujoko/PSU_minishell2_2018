/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** yes
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_
#include "my.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define SAVE_PATH "/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
#define FILE_RIGHT "S_IRUSR + S_IWUSR + S_IRGRP + S_IWGRP + S_IROTH"
extern int errno;

typedef struct shell_s{
    char **path;
    char **command;
    char **envp;
    pid_t trident;
    char *actual;
    char *save;
    char *buffer;
    int howmanys;
    int status;
    int pipes;
    int saves[2];
}   shell_t;

void restore_fd(shell_t *mysh);
void prompt(shell_t *mysh);
int get_command(shell_t *mysh);
void actual_file(shell_t *mysh);
int test_buffer(shell_t *mysh);
int cd_command(shell_t *mysh);
void env_command(shell_t *mysh);
int setenv_command(shell_t *mysh);
int unsetenv_command(shell_t *mysh);
int check_inside_file(shell_t *mysh);
char **get_cleaned(char *buffer, char limit);
int find_size(char **tab);
int my_isalpha(char *newenv);
void exit_command(shell_t *mysh);
void check_status(shell_t *mysh, int status);
int update_env_no_arg(shell_t *mysh);
int update_env_minus(shell_t *mysh);
int update_env_one_arg(shell_t *mysh);
char **env_realloc(shell_t *mysh, char *newenv, char *value);
int search_env(shell_t *mysh, char *quest);
void getting_actual_dir_name(shell_t *mysh);
void testing_path(shell_t *mysh);
int find_redirections(shell_t *mysh);
void get_pathed(shell_t *mysh);
void testing_path(shell_t *mysh);
void execution_mistake(shell_t *mysh);
void my_exec(shell_t *mysh, int path);
#endif /* !MINISHELL_H_ */
