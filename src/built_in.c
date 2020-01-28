/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.c
*/

#include "minishell1.h"

static void replace_env(int pos, char **av, char **env)
{
    int len = my_strlen(av[1]) + my_strlen(av[2]) + 1;
    char *new_env;
    char *dest = malloc(sizeof(char) * len + 1);

    dest[0] = '\0';
    new_env = my_strcat(dest, av[1]);
    new_env = my_strcat(new_env, "=");
    new_env = my_strcat(new_env, av[2]);
    env[pos] = new_env;
}

static void create_env(char **env, char **av)
{
    int len;
    char *new_env;
    char *dest;
    int i = 0;

    if (av[2])
        len = my_strlen(av[1]) + my_strlen(av[2]) + 1;
    else
        len = my_strlen(av[1]) + 1;
    dest = malloc(sizeof(char) * len + 1);
    dest[0] = '\0';
    new_env = my_strcat(dest, av[1]);
    new_env = my_strcat(new_env, "=");
    if (av[2])
        new_env = my_strcat(new_env, av[2]);
    while (env[i] != NULL)
        i++;
    env[i] = new_env;
    env[i + 1] = NULL;
}

int my_setenv(char **env, char **av)
{
    int ac = 0;
    int pos = find_path_number(env, av[1]);

    for (; av[ac] != NULL; ac++);
    if (ac > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return 84;
    }
    if (pos >= 0)
        replace_env(pos, av, env);
    else
        create_env(env, av);
    return 0;
}

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

void my_cd(char **env, char **av)
{

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