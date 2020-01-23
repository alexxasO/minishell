/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.c
*/

#include "minishell1.h"

void replace_env(int pos, char *new_var, char **env)
{
    env[pos] = new_var;
}

void my_setenv(char **env, char *env_to_set)
{
    char *beg = find_env_name(env_to_set);
    int pos = find_path_number(env, beg);

    if (pos >= 0)
        replace_env(pos, env_to_set, env);
    // else
    //     //set new env
}

int built_in_cmd(char **env, char **av)
{
    if (!my_strcmp(av[0], "setenv")) {
        my_putstr("SETENV !!!\n");
        return 0;
    }
    return 1;
}