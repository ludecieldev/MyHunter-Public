/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
** File description:
** my_hunter.h
** Author:
** ludeciel
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdarg.h>
#include <pwd.h>
#include <grp.h>

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} sprite_s_t;

int mini_printf(char const *format, ...);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int format_integer(int i, char const *format, va_list list, int count);
int format_string(int i, char const *format, va_list list , int count);
int format_char(int i, char const *format, va_list list, int count);
int format_modulo(int i, char const *format, va_list list, int count);

char *screen_create(sfVideoMode mode, char *title);
char *screen_display(sfRenderWindow *window);

#endif /* !MY_HUNTER_H_ */