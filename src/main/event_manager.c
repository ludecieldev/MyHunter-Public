/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** event_manager.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void mouse_getter(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            my_putstr("X = ");
            my_put_nbr(event.mouseButton.x);
            my_putstr(" Y = ");
            my_put_nbr(event.mouseButton.y);
            my_putchar('\n');
        }
    }
}

void check_player_position(sfRenderWindow *window, sfEvent event, mob_t *mob)
{
    if (event.mouseButton.x >= mob->x && event.mouseButton.x <= mob->x + 100
    && event.mouseButton.y >= mob->y && event.mouseButton.y <= mob->y + 100) {
        mob->x = -200;
        sfMusic_play(mob->hit);
        sfSprite_setPosition(mob->sprite, (sfVector2f){mob->x, mob->y});
    }
}

void event_manager(sfRenderWindow *window, sfEvent event, mob_t *mob)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_getter(window, event);
            check_player_position(window, event, mob);
        }
    }
}
