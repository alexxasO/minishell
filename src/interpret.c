/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** interpret.c
*/

#include "minishell1.h"

static char *stock_dir(char **paths)
{
    int i = 0;
    char *dir = malloc(sizeof(char) * my_strlen(*paths) + 1);
    int len = my_strlen(*paths);

    while (i <= len && (*paths)[0] != ':' && (*paths)[0] != '\0') {
        dir[i] = (*paths)[0];
        (*paths)++;
        i++;
    }
    dir[i] = '\0';
    if ((*paths)[0] != '\0')
        (*paths)++;
    return dir;
}

void launch_the_bin(char *path, char **av, char **env)
{
    int child_pid = fork();

    if (child_pid == 0) {
        if (execve(path, av, env) == -1) {
            strerror(errno);
            exit(0);
        }
    }
    waitpid(child_pid, NULL, 0);
}

int find_the_bin(struct dirent *rd, DIR *directory, cmd_info *cmd,
                    char **env)
{
    while (rd) {
        if (my_strcmp(rd->d_name, cmd->cmd) == 0) {
            launch_the_bin(cmd->full_cmd, cmd->args, env);
            return 0;
        }
        rd = readdir(directory);
    }
    return 1;
}

void run_from_env(char **env, char **cmd, char *paths)
{
    char *dir;
    DIR *directory;
    struct dirent *rd;
    cmd_info cmdinf = {cmd[0], NULL, cmd};
    char *cmd_with_slash = my_strcat_malloc("/", cmd[0]);
    int stop = 1;

    paths += my_strlen("PATH=");
    while (stop && my_strlen(paths) > 0) {
        dir = stock_dir(&paths);
        directory = opendir(dir);
        rd = readdir(directory);
        cmdinf.full_cmd = my_strcat_malloc(dir, cmd_with_slash);
        if (!built_in_cmd(env, cmd))
            break;
        stop = find_the_bin(rd, directory, &cmdinf, env);
    }
    if (stop == 1) {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
    }
    free(cmd_with_slash);
    free(dir);
}

void run_from_path(char **env, char **cmd)
{
    if (access(cmd[0], X_OK) == -1) {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
    }
    else
        launch_the_bin(cmd[0], cmd, env);
}

int interpret(char **env, char **cmd)
{
    char *paths;

    if (cmd[0][0] == '/') {
        run_from_path(env, cmd);
        return 0;
    }
    if (find_path_number(env, "PATH") != -1) {
        paths = env[find_path_number(env, "PATH")];
        run_from_env(env, cmd, paths);
        return 0;
    }
    if (!built_in_cmd(env, cmd))
        return 0;
    my_putstr(cmd[0]);
    my_putstr(": Command not found.\n");
    return 84;
}