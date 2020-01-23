/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** globalfunc.c
*/

#include "minishell1.h"

char *find_env_name(char *env_line)
{
    char *to_ret = malloc(sizeof(char) * my_strlen(env_line));
    int i = 0;

    while (env_line[i] != '=' && env_line[i] != '\0') {
        to_ret[i] = env_line[i];
        i++;
    }
    to_ret[i] = '\0';
    return to_ret;
}