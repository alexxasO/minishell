/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** starts_with.c
*/

int my_strlen(char const *str);

int starts_with(char const *str, char *comp)
{
    if (my_strlen(comp) > my_strlen(str))
        return 0;
    for (int i = 0; comp[i] != '\0'; i++)
        if (str[i] != comp[i])
            return 0;
    return 1;
}