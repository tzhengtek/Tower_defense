/*
** EPITECH PROJECT, 2021
** my_printf.h
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

int open_file(char const *filepath);
void print_error(char *str);
void my_putarr(char **array);
char **str_to_array(char *str, char c, char t);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *int_to_char(int nb);
int my_getnbr(char *new_str);

#endif
