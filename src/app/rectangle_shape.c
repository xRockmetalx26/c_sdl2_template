//
// Created by xRockmetalx
//

#include <app/rectangle_shape.h>

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL_render.h>

#include <app/rectangle_shape.h>
#include <app/texture.h>

RectangleShape* new_rectangle_shape(const int x, const int y, const int width, const int height) {
    RectangleShape *rectangle_shape = (RectangleShape*) calloc(1, sizeof (RectangleShape));

    if(!rectangle_shape) {
        puts("ERROR new_rectangle_shape().");
        exit(EXIT_FAILURE);
    }

    rectangle_shape->transformable.rectangle.x = x;
    rectangle_shape->transformable.rectangle.y = y;
    rectangle_shape->transformable.rectangle.w = width;
    rectangle_shape->transformable.rectangle.h = height;
    rectangle_shape->transformable.scale.x = 1;
    rectangle_shape->transformable.scale.y = 1;
    rectangle_shape->color.a = 255;
    rectangle_shape->color_border.a = 255;

    return rectangle_shape;
}

void load_rgba(SDL_Renderer *renderer, RectangleShape *rectangle_hape) {
    delete_texture(rectangle_hape->texture);

    rectangle_hape->texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        rectangle_hape->transformable.rectangle.w,
        rectangle_hape->transformable.rectangle.h
    );

    if(!rectangle_hape->texture) {
        puts("ERROR SDL_CreateTexture().");
        exit(EXIT_FAILURE);
    }

    SDL_SetTextureBlendMode(rectangle_hape->texture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer, rectangle_hape->texture);

    SDL_SetRenderDrawColor(renderer, rectangle_hape->color.r, rectangle_hape->color.g, rectangle_hape->color.b, rectangle_hape->color.a);
    SDL_RenderFillRect(renderer, NULL);

    SDL_Rect rect_border = {
        rectangle_hape->border_size,
        rectangle_hape->border_size,
        rectangle_hape->transformable.rectangle.w - rectangle_hape->border_size * 2,
        rectangle_hape->transformable.rectangle.h - rectangle_hape->border_size * 2
    };

    SDL_SetRenderDrawColor(renderer, rectangle_hape->color.r, rectangle_hape->color.g, rectangle_hape->color.b, rectangle_hape->color.a);
    SDL_RenderFillRect(renderer, &rect_border);

    SDL_SetRenderTarget(renderer, NULL);
}

void draw_rectangle_shape(SDL_Renderer *renderer, RectangleShape *rectangle_hape) {
    const SDL_Point center = {rectangle_hape->transformable.rectangle.w / 2, rectangle_hape->transformable.rectangle.h / 2};
    const SDL_Rect dest_rect = {
        rectangle_hape->transformable.rectangle.x,
        rectangle_hape->transformable.rectangle.y,
        rectangle_hape->transformable.rectangle.w * rectangle_hape->transformable.scale.x,
        rectangle_hape->transformable.rectangle.h * rectangle_hape->transformable.scale.y
    };

    SDL_RenderCopyEx(renderer, rectangle_hape->texture, NULL, &dest_rect, rectangle_hape->transformable.rotation, &center, SDL_FLIP_NONE);
}

void delete_rectangle_shape(RectangleShape *rectangle_shape) {
    if(rectangle_shape) {
        delete_texture(rectangle_shape->texture);
        free(rectangle_shape);
    }
}
