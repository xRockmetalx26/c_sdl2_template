//
// Created by xRockmetalx
//

#ifndef LABEL_H
#define LABEL_H

#include <app/transformable.h>

typedef struct SDL_Texture SDL_Texture;
typedef struct SDL_Renderer SDL_Renderer;

typedef struct Label {
    SDL_Texture *texture;
    Transformable transformable;
    SDL_Color color;

    char font_filename[33];
    char text[257];
    int point_size;
} Label;

Label* new_label(int x, int y, int width, int height);

void load_text(SDL_Renderer *renderer, Label *label, const char *font_filename, const char *text);

void draw_label(SDL_Renderer *renderer, Label *label);

void delete_label(Label *label);

#endif // LABEL_H
