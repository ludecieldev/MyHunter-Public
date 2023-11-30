/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** init.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void init_windows(window_t *window)
{
    window->mode.width = 1792;
    window->mode.height = 1024;
    window->mode.bitsPerPixel = 32;
    window->title = "My Hunter";
}

void init_textures(textures_t *textures)
{
    textures->menu_texture = sfTexture_createFromFile("assets/g_m.png", NULL);
    textures->menu_sprite = sfSprite_create();
    sfSprite_setTexture(textures->menu_sprite, textures->menu_texture, sfTrue);
    textures->game_texture = sfTexture_createFromFile("assets/back.png", NULL);
    textures->game_sprite = sfSprite_create();
    sfSprite_setTexture(textures->game_sprite, textures->game_texture, sfTrue);
}

void init_music(music_t *music)
{
    music->music = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_play(music->music);
}

void init_mob(mob_t *mob)
{
    mob->clock = sfClock_create();
    mob->time = sfClock_getElapsedTime(mob->clock);
    mob->seconds = 0;
    mob->rect.top = 0;
    mob->rect.left = 0;
    mob->rect.width = 85;
    mob->rect.height = 85;
    mob->x = 0;
    mob->y = 845;
    mob->sprite_texture = sfTexture_createFromFile("assets/link_ltr.png",
    NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setPosition(mob->sprite, (sfVector2f){mob->x, mob->y});
    sfSprite_setTexture(mob->sprite, mob->sprite_texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->rect);
    mob->hit = sfMusic_createFromFile("assets/hit.ogg");
}

int error_texture(textures_t *textures, mob_t *mob)
{
    if (!textures->menu_texture || !textures->menu_sprite ||
    !textures->game_texture || !textures->game_sprite ||
    !mob->sprite_texture || !mob->sprite)
        return (84);
    return (0);
}
