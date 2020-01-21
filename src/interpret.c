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
    char *dir = malloc(sizeof(char) * my_strlen(*paths));

    while ((*paths)[i] != ':')
    {
        dir[i] = (*paths)[i];
        (*paths)++;
    }
    (*paths)++;
    return dir;
}

int interpret(char **env)
{
    char *paths = env[find_path_number(env)];

    paths += 5;
    return 0;
}