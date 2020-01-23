/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "minishell1.h"

void display_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        printf("%s\n", env[i]);
}

int find_path_number(char **env, char *name)
{
    int i = 0;

    while (!starts_with(env[i], name) && env[i] != NULL)
        i++;
    if (env[i] == NULL)
        return -1;
    return i;
}

int minishell(char **env)
{
    char *cmd = NULL;
    size_t n = 0;
    char **av;
    int getl;

    while (1) {
        my_putstr("$The_cake_is_a_lie_shell> ");
        getl = getline(&cmd, &n, stdin);
        cmd[my_strlen(cmd) - 1] = '\0';
        av = my_explode(cmd, ' ');
        if (getl == -1) {
            break;
        }
        else
            interpret(env, av);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (ac > 1)
        return 84;
    minishell(env);
    return 0;
}