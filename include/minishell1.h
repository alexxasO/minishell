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

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int starts_with(char const *str, char *comp);
int interpret(char **env);
int find_path_number(char **env);

#endif