//
// Created by xRockmetalx
//

#ifndef RECTANGLE_SHAPE_H
#define RECTANGLE_SHAPE_H

#include <app/transformable.h>

typedef struct SDL_Texture SDL_Texture;
typedef struct SDL_Renderer SDL_Renderer;

typedef struct RectangleShape {
    SDL_Texture *texture;
    Transformable transformable;
    SDL_Color color;
    SDL_Color color_border;

    int border_size;
} RectangleShape;

RectangleShape* new_rectangle_shape(int x, int y, int width, int height);

void load_rgba(SDL_Renderer *renderer, RectangleShape *rectangle_hape);

void draw_rectangle_shape(SDL_Renderer *renderer, RectangleShape *rectangle_hape);

void delete_rectangle_shape(RectangleShape *rectangle_shape);

#endif // RECTANGLE_SHAPE_H
