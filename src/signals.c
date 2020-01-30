/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** signals.c
*/

#include "minishell1.h"

int sigsev_handler(int sig)
{
    if (sig == 8) {
        my_putstr_error("floating exception\n");
        return 1;
    } else if (sig) {
        my_putstr_error(strsignal(sig));
        return 1;
    }
    return 0;
}