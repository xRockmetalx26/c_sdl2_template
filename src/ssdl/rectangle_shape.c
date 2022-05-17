//
// Created by xRockmetalx
//

#include <ssdl/rectangle_shape.h>

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL_render.h>

#include <ssdl/rectangle_shape.h>
#include <ssdl/texture.h>

RectangleShape new_rectangle_shape(Texture texture, const int x, const int y, const int width, const int height) {
    RectangleShape rectangle_shape = (RectangleShape) calloc(1, RECTANGLE_SHAPE_SIZE);
    if(!rectangle_shape) {
        fprintf(stderr, "ERROR in new_rectangle_shape(), calloc() is null.\n");
        return NULL;
    }

    rectangle_shape->texture = texture;
    rectangle_shape->transformable.position.x = x;
    rectangle_shape->transformable.position.y = y;
    rectangle_shape->transformable.dimensions.width = width;
    rectangle_shape->transformable.dimensions.height = height;
    rectangle_shape->transformable.scale.width = 1;
    rectangle_shape->transformable.scale.height = 1;
    rectangle_shape->color.a = 255;
    rectangle_shape->color_border.a = 255;

    return rectangle_shape;
}

void draw_rectangle_shape(Renderer renderer, RectangleShape rectangle_hape) {
    const Point center = {rectangle_hape->transformable.dimensions.width / 2, rectangle_hape->transformable.dimensions.height / 2};
    const Rectangle dest_rectangle = {
        rectangle_hape->transformable.position.x,
        rectangle_hape->transformable.position.y,
        rectangle_hape->transformable.dimensions.width * rectangle_hape->transformable.scale.width,
        rectangle_hape->transformable.dimensions.height * rectangle_hape->transformable.scale.height
    };

    SDL_RenderCopyEx(renderer, rectangle_hape->texture, NULL, &dest_rectangle, rectangle_hape->transformable.rotation, &center, SDL_FLIP_NONE);
}

void delete_rectangle_shape(void *rectangle_shape) {
    RectangleShape to_delete = (RectangleShape) rectangle_shape;
    if(to_delete) {
        free(to_delete);
    }
}
