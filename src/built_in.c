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

void create_env(char **env, char **av)
{
    int len = my_strlen(av[1]) + my_strlen(av[2]) + 1;
    char *new_env;
    char *dest = malloc(sizeof(char) * len + 1);
    int i = 0;

    dest[0] = '\0';
    new_env = my_strcat(dest, av[1]);
    new_env = my_strcat(new_env, "=");
    new_env = my_strcat(new_env, av[2]);
    while(env[i] != NULL)
        i++;
    env[i] = new_env;
    env[i + 1] = NULL;
}

void my_setenv(char **env, char **av)
{
    int pos = find_path_number(env, av[1]);

    if (pos >= 0)
        replace_env(pos, av, env);
    else
        create_env(env, av);
}

int built_in_cmd(char **env, char **av)
{
    if (!my_strcmp(av[0], "setenv")) {
        my_setenv(env, av);
        return 0;
    }
    return 1;
}