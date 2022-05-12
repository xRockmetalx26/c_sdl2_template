//
// Created by xRockmetalx
//

#include <app/sprite.h>

#include <sdl2/SDL_image.h>
#include <sdl2/SDL_rect.h>

#include <app/texture.h>
#include <stdio.h>

Sprite* new_sprite(const int x, const int y, const int width, const int height) {
    Sprite *sprite = (Sprite*) calloc(1, sizeof (Sprite));

    if(!sprite) {
        puts("ERROR new_sprite().");
        exit(EXIT_FAILURE);
    }

    sprite->transformable.rectangle.x = x;
    sprite->transformable.rectangle.y = y;
    sprite->transformable.rectangle.w = width;
    sprite->transformable.rectangle.h = height;
    sprite->transformable.scale.x = 1;
    sprite->transformable.scale.y = 1;

    return sprite;
}

void load_image(SDL_Renderer *renderer, Sprite *sprite, const char *filename) {
    delete_texture(sprite->texture);

    SDL_Surface *surface = IMG_Load(filename);

    if(!surface) {
        puts("ERROR IMG_Load().");
        exit(EXIT_FAILURE);
    }

    sprite->texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(!sprite->texture) {
        puts("ERROR SDL_CreateTextureFromSurface().");
        exit(EXIT_FAILURE);
    }

    SDL_FreeSurface(surface);

    sprite->rectangle = get_texture_size(sprite->texture);
}

void draw_sprite(SDL_Renderer *renderer, Sprite *sprite) {
    const SDL_Point center = {sprite->transformable.rectangle.w / 2, sprite->transformable.rectangle.h / 2};
    const SDL_Rect dest_rect = {
        sprite->transformable.rectangle.x,
        sprite->transformable.rectangle.y,
        sprite->transformable.rectangle.w * sprite->transformable.scale.x,
        sprite->transformable.rectangle.h * sprite->transformable.scale.y
    };

    SDL_RenderCopyEx(renderer, sprite->texture, &sprite->rectangle, &dest_rect, sprite->transformable.rotation, &center, SDL_FLIP_NONE);
}

void delete_sprite(Sprite *sprite) {
    if(sprite) {
        delete_texture(sprite->texture);
        free(sprite);
    }
}
