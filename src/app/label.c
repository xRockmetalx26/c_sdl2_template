//
// Created by xRockmetalx
//

#include <app/label.h>

#include <stdio.h>

#include <sdl2/SDL_ttf.h>

#include <app/render_window.h>
#include <app/texture.h>

Label* new_label(const int x, const int y, const int width, const int height) {
    Label *label = (Label*) calloc(1, sizeof (Label));

    if(!label) {
        puts("ERROR new_label().");
        exit(EXIT_FAILURE);
    }

    label->transformable.rectangle.x = x;
    label->transformable.rectangle.y = y;
    label->transformable.rectangle.w = width;
    label->transformable.rectangle.h = height;
    label->transformable.scale.x = 1;
    label->transformable.scale.y = 1;
    label->point_size = 12;
    label->color.a = 255;

    return label;
}

void load_text(SDL_Renderer *renderer, Label *label, const char *font_filename, const char *text) {
    delete_texture(label->texture);

    TTF_Font *font = TTF_OpenFont(font_filename, label->point_size);

    if(!font) {
        puts("ERROR TTF_OpenFont().");
        exit(EXIT_FAILURE);
    }

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, label->color);

    if(!surface) {
        puts("ERROR TTF_RenderText_Solid().");
        exit(EXIT_FAILURE);
    }

    label->texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(!label->texture) {
        puts("ERROR SDL_CreateTextureFromSurface().");
        exit(EXIT_FAILURE);
    }

    SDL_FreeSurface(surface);
}

void draw_label(SDL_Renderer *renderer, Label *label) {
    const SDL_Point center = {label->transformable.rectangle.w / 2, label->transformable.rectangle.h / 2};
    const SDL_Rect dest_rect = {
        label->transformable.rectangle.x,
        label->transformable.rectangle.y,
        label->transformable.rectangle.w * label->transformable.scale.x,
        label->transformable.rectangle.h * label->transformable.scale.y
    };

    SDL_RenderCopyEx(renderer, label->texture, NULL, &dest_rect, label->transformable.rotation, &center, SDL_FLIP_NONE);
}

void delete_label(Label *label) {
    if(label) {
        delete_texture(label->texture);
        free(label);
    }
}
