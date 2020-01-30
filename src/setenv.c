/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv.c
*/

#include "minishell1.h"

static int check_letter(char c)
{
    if (c >= '0' && c <= '9') {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    return 0;
}

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
        my_putstr_error("setenv: Too many arguments.\n");
        return 84;
    }
    if (ac < 2) {
        display_env(env);
        return 84;
    }
    if (check_letter(av[1][0]))
        return 0;
    if (pos >= 0)
        replace_env(pos, av, env);
    else
        create_env(env, av);
    return 0;
}