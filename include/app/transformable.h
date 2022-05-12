//
// Created by xRockmetalx
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include <sdl2/SDL_rect.h>

typedef struct Transformable {
    SDL_Rect rectangle;
    SDL_Point scale;

    float rotation;
} Transformable;

void move(Transformable *transformable, int dx, int dy);

#endif // TRANSFORMABLE_H
