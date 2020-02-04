/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_isalpha.c
*/

int my_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            return 1;
        if (str[i] >= 'A' && str[i] <= 'Z')
            return 1;
        if (str[i] >= '0' && str[i] <= '9')
            return 1;
    }
    return 0;
}

int my_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
    return 1;
}