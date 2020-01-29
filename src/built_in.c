/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.c
*/

#include "minishell1.h"

int my_unsetenv(char **env, char **av)
{
    int i = 0;
    int pos = find_path_number(env, av[1]);

    if (!av[1])
        my_putstr("unsetenv: Too few arguments.\n");
    for (; env[i] != NULL; i++);
    if (i == 0 || pos < 0)
        return 0;
    env[pos] = env[i - 1];
    env[i - 1] = NULL;
    return 0;
}

int my_cd(char **env, char **av)
{
    int ac = 0;

    for (; av[ac] != NULL; ac++);
    if (ac > 2) {
        my_putstr("cd: Too many arguments.\n");
        return 84;
    }
    if (ac == 2) {
        if (chdir(av[1])  < 0)
            perror(strerror(errno));
        else
            cd_setenv(env, av);
    }
    return 0;
}

int built_in_cmd(char **env, char **av)
{
    if (!my_strcmp(av[0], "setenv")) {
        my_setenv(env, av);
        return 0;
    }
    if (!my_strcmp(av[0], "env")) {
        display_env(env);
        return 0;
    }
    if (!my_strcmp(av[0], "unsetenv")) {
        my_unsetenv(env, av);
        return 0;
    }
    if (!my_strcmp(av[0], "cd")) {
        my_cd(env, av);
        return 0;
    }
    return 1;
}