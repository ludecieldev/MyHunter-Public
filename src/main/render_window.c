/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** render_window.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void destroy_all(window_t *window, textures_t *textures, mob_t *mob)
{
    sfRenderWindow_destroy(window->window);
    sfTexture_destroy(textures->menu_texture);
    sfSprite_destroy(textures->menu_sprite);
    sfTexture_destroy(textures->game_texture);
    sfSprite_destroy(textures->game_sprite);
    sfTexture_destroy(mob->sprite_texture);
    sfSprite_destroy(mob->sprite);
}

void while_short(window_t *window, textures_t *textures, mob_t *mob)
{
    event_manager(window->window, window->event, mob);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, textures->game_sprite, NULL);
    sfRenderWindow_drawSprite(window->window, mob->sprite, NULL);
    mob_animation(mob);
    sfRenderWindow_display(window->window);
}

void render_window(void)
{
    window_t window;
    textures_t textures;
    mob_t mob;
    music_t music;

    init_windows(&window);
    init_textures(&textures);
    init_mob(&mob);
    init_music(&music);
    window.window = sfRenderWindow_create(window.mode, window.title,
    sfResize | sfClose, NULL);
    if (error_texture(&textures, &mob) == 84)
        return;
    sfRenderWindow_setFramerateLimit(window.window, 144);
    while (sfRenderWindow_isOpen(window.window)) {
        while_short(&window, &textures, &mob);
    }
    destroy_all(&window, &textures, &mob);
}