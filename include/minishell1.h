/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell1.h
*/

#ifndef MINISHELL1
#define MINISHELL1

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int starts_with(char const *str, char *comp);
int interpret(char **env, char **cmd);
int find_path_number(char **env, char *name);
char *my_strcat_malloc(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char **my_explode(char *str, char sep);
char *my_strdup(char const *src);
char *find_env_name(char *env_line);
int built_in_cmd(char **env, char **av);

typedef struct {
    char *cmd;
    char *full_cmd;
    char **args;
} cmd_info;

#endif