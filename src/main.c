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

int find_path_number(char **env)
{
    int i = 0;

    while (!starts_with(env[i], "PATH"))
        i++;
    return i;
}

int minishell(char **env)
{
    FILE *stream = fdopen(0, "r");
    char *cmd = NULL;
    size_t n = 0;
    char **av;

    while (1) {
        my_putstr("$The_cake_is_a_lie_shell> ");
        getline(&cmd, &n, stream);
        cmd[my_strlen(cmd) - 1] = '\0';
        av = my_explode(cmd, ' ');
        if (cmd[0] == 0) {
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