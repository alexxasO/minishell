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

void launch_the_bin(char *path, char **env)
{
    int child_pid = fork();
    char *av[] = {"ls", NULL};

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
        if (strcmp(rd->d_name, cmd->cmd) == 0) { // strcmp
            launch_the_bin(cmd->full_cmd, env);
            return 0;
        }
        rd = readdir(directory);
    }
    return 1;
}

int interpret(char **env, char *cmd)
{
    char *paths = env[find_path_number(env)];
    char *dir;
    DIR *directory;
    struct dirent *rd;
    cmd_info cmdinf = {cmd, NULL};
    char *cmd_with_slash = my_strcat_malloc("/", cmd);

    paths += 5;
    while (paths[0] != '\0') {
        dir = stock_dir(&paths);
        directory = opendir(dir);
        rd = readdir(directory);
        cmdinf.full_cmd = my_strcat_malloc(dir, cmd_with_slash);
        if (!find_the_bin(rd, directory, &cmdinf, env))
            break;
        free(cmdinf.full_cmd);
    }
    free(cmd_with_slash);
    free(dir);
    return 0;
}