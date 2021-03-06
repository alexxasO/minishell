/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** interpret.c
*/

#include "minishell1.h"

void launch_the_bin(char *path, char **av, char **env)
{
    int child_pid = fork();
    int status = 0;

    if (child_pid == 0) {
        if (execve(path, av, env) == -1) {
            strerror(errno);
            exit(0);
        }
    }
    waitpid(child_pid, &status, 0);
    if (WIFSIGNALED(status) && !WIFEXITED(status)) {
        sigsev_handler(status);
    }
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

    if (!built_in_cmd(env, cmd))
        return 0;
    if (cmd[0][0] == '/' || cmd[0][0] == '.') {
        run_from_path(env, cmd);
        return 0;
    }
    if (str_contain(cmd[0], '/')) {
        run_from_path(env, cmd);
        return 0;
    }
    if (find_path_number(env, "PATH") != -1) {
        paths = env[find_path_number(env, "PATH")];
        run_from_env(env, cmd, paths);
        return 0;
    }
    my_putstr(cmd[0]);
    my_putstr(": Command not found.\n");
    return 84;
}