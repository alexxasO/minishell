/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** signals.c
*/

#include "minishell1.h"

void sigsev_handler(int sig)
{
    printf("caught signal %d\n", sig);
}