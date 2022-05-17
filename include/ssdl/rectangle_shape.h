//
// Created by xRockmetalx
//

#ifndef RECTANGLE_SHAPE_H
#define RECTANGLE_SHAPE_H

#define RECTANGLE_SHAPE_SIZE sizeof (struct _RectangleShape)

#include <ssdl/types.h>
#include <ssdl/transformable.h>

struct _RectangleShape {
    Texture texture;
    Transformable transformable;
    Color color;
    Color color_border;

    int border_size;
};

RectangleShape new_rectangle_shape(Texture texture, int x, int y, int width, int height);

void draw_rectangle_shape(Renderer renderer, RectangleShape rectangle_shape);

void delete_rectangle_shape(void *rectangle_shape);

#endif // RECTANGLE_SHAPE_H
