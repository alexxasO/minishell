/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "minishell1.h"

int starts_with(char const *str, char *comp)
{
    if (my_strlen(comp) > my_strlen(str))
        return 0;
    for (int i = 0; comp[i] != '\0'; i++)
        if (str[i] != comp[i])
            return 0;
    return 1;
}

void display_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        printf("%s\n", env[i]);
}

int minishell(char **env)
{
    FILE *stream = fdopen(0, "r");
    char *cmd = NULL;
    size_t n = 0;

    while (1) {
        my_putstr("$> ");
        getline(&cmd, &n, stream);
        if (cmd[0] == 0) {
            my_putstr("exit");
            break;
        }
        else
            return 42;
    }
}

int main(int ac, char **av, char **env)
{
    if (ac > 1)
        return 84;
    minishell(env);
    return 0;
}