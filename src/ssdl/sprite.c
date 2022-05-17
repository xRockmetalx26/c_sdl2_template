//
// Created by xRockmetalx
//

#include <ssdl/sprite.h>

#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_render.h>

#include <ssdl/texture.h>

Sprite new_sprite(Texture texture, const int x, const int y, const int width, const int height) {
    Sprite sprite = (Sprite) calloc(1, SPRITE_SIZE);
    if(!sprite) {
        fprintf(stderr, "ERROR in new_sprite(), calloc() is null.\n");
        return NULL;
    }

    sprite->texture = texture;
    sprite->transformable.position.x = x;
    sprite->transformable.position.y = y;
    sprite->transformable.dimensions.width = width;
    sprite->transformable.dimensions.height = height;
    sprite->transformable.scale.width = 1;
    sprite->transformable.scale.height = 1;

    Dimensions dimensions = get_texture_size(texture);
    sprite->rectangle_texture.w = dimensions.width;
    sprite->rectangle_texture.h = dimensions.height;

    return sprite;
}

void set_texture_sprite(Sprite sprite, Texture texture) {
    if(sprite && texture) {
        sprite->texture = texture;
        sprite->transformable.dimensions = get_texture_size(texture);
    }
}

void draw_sprite(Renderer renderer, Sprite sprite) {
    const Point center = {sprite->transformable.dimensions.width / 2, sprite->transformable.dimensions.height / 2};
    const Rectangle dest_rectangle = {
        sprite->transformable.position.x,
        sprite->transformable.position.y,
        sprite->transformable.dimensions.width * sprite->transformable.scale.width,
        sprite->transformable.dimensions.height * sprite->transformable.scale.height
    };

    SDL_RenderCopyEx(renderer, sprite->texture, &sprite->rectangle_texture, &dest_rectangle, sprite->transformable.rotation, &center, SDL_FLIP_NONE);
}

void delete_sprite(void *sprite) {
    Sprite to_delete = (Sprite) sprite;
    if(to_delete) {
        free(to_delete);
    }
}
