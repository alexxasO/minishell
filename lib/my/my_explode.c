/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h> //debug

int my_strlen(char const *str);
char *my_strdup(char const *src);

static int count_char(char *str, char ch)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            count ++;
    return count;
}

char **my_explode(char *str, char sep)
{
    int sep_count = count_char(str, sep);
    char **tab = malloc(sizeof(char *) * sep_count + 2);
    char *cpy = my_strdup(str);
    int i = 0;

    if (str == NULL)
        return NULL;
    for (i = 0; i < sep_count + 1; i++) {
        tab[i] = malloc(sizeof(char) * my_strlen(cpy) + 1);
        for (int j = 0; cpy[0] != sep && cpy[0] != '\0'; j++) {
            tab[i][j] = cpy[0];
            cpy++;
        }
        printf("tab[%d] = %s\n", i, tab[i]);
        cpy++;
    }
    tab[i] = NULL;
    printf("tab[%d] = %s\n", i, tab[i]);
    return tab;
}