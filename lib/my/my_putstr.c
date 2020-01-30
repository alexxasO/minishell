/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** displays one by one each characters of a string
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    if (!str) {
        my_putstr("(null)");
        return 0;
    }
    write(1, str, my_strlen(str));
    return (0);
}
