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
#include <sys/stat.h>
#include <signal.h>
#include <string.h>

#define READ_SIZE 12345
#define UN __attribute__((unused))
#define BLACK "\e[1;30m"
#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define MAGENTA "\e[1;35m"
#define CYAN "\e[1;36m"
#define WHITE "\e[1;37m"
#define SHELL "\e[;m"
#define RODE "\e[9;30m"
#define BOLD "\e[01;30m"
#define FLASH "\e[5;30m"


int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_putstr_error(char const *str);
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
char *my_strcat(char *dest, char const *src);
void display_env(char **env);
int my_setenv(char **env, char **av);
void run_from_env(char **env, char **cmd, char *paths);
void launch_the_bin(char *path, char **av, char **env);
int cd_setenv(char **env);
int str_contain(char *str_to_check, char char_to_find);

typedef struct {
    char *cmd;
    char *full_cmd;
    char **args;
} cmd_info;

#endif