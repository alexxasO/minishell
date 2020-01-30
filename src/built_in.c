/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.c
*/

#include "minishell1.h"

static int check_cd_error(char **env)
{
    if (find_path_number(env, "HOME=") < 0) {
        my_putstr_error("cd: No home directory.\n");
        return 0;
    }
    return 1;
}

static void prt_err_cd(char *str)
{
    my_putstr_error(str);
    my_putstr_error(": ");
    perror(NULL);
}

int my_unsetenv(char **env, char *av)
{
    int i = 0;
    int pos = find_path_number(env, av);

    if (!av)
        my_putstr_error("unsetenv: Too few arguments.\n");
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
        my_putstr_error("cd: Too many arguments.\n");
    }
    if (ac == 2) {
        if (chdir(av[1]) < 0)
            prt_err_cd(av[1]);
        else
            cd_setenv(env);
    }
    if (ac == 1 && check_cd_error(env)) {
        if (chdir(env[find_path_number(env, "HOME=")] + 5) < 0)
            prt_err_cd(env[find_path_number(env, "HOME=")] + 5);
        else
            cd_setenv(env);
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
        for (int i = 1; av[i] != NULL; i++)
            my_unsetenv(env, av[i]);
        return 0;
    }
    if (!my_strcmp(av[0], "cd")) {
        my_cd(env, av);
        return 0;
    }
    return 1;
}