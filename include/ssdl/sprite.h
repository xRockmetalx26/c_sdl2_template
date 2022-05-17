//
// Created by xRockmetalx
//

#ifndef SPRITE_H
#define SPRITE_H

#define SPRITE_SIZE sizeof (struct _Sprite)

#include <ssdl/types.h>
#include <ssdl/transformable.h>

struct _Sprite {
    Texture texture;
    Transformable transformable;
    Rectangle rectangle_texture;
};

Sprite new_sprite(Texture texture, int x, int y, int width, int height);

void set_texture_sprite(Sprite sprite, Texture texture);

void draw_sprite(Renderer renderer, Sprite sprite);

void delete_sprite(void *sprite);

#endif // SPRITE_H
