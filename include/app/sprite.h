//
// Created by xRockmetalx
//

#ifndef SPRITE_H
#define SPRITE_H

#include <sdl2/SDL_rect.h>

#include <app/transformable.h>

typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Texture SDL_Texture;

typedef struct Sprite {
    SDL_Texture *texture;
    Transformable transformable;
    SDL_Rect rectangle;
} Sprite;

Sprite* new_sprite(int x, int y, int width, int height);

void load_image(SDL_Renderer *renderer, Sprite *sprite, const char *filename);

void draw_sprite(SDL_Renderer *renderer, Sprite *sprite);

void delete_sprite(Sprite *sprite);

#endif // SPRITE_H
