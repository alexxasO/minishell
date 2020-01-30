/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd_setenv.c
*/

#include "minishell1.h"

int cd_setenv(char **env)
{
    int len = READ_SIZE;
    char *buf = malloc(sizeof(char) * len);
    char **av_pwd = malloc(sizeof(char *) * 4);

    getcwd(buf, len);
    av_pwd[0] = "setenv";
    av_pwd[1] = "PWD";
    av_pwd[2] = buf;
    av_pwd[3] = NULL;
    my_setenv(env, av_pwd);
    free(av_pwd);
    free(buf);
    return 0;
}