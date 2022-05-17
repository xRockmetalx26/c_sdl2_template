//
// Created by xRockmetalx
//

#include <ssdl/label.h>

#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_render.h>

#include <ssdl/texture.h>

Label new_label(Texture texture, const int x, const int y, const int width, const int height) {
    Label label = (Label) calloc(1, LABEL_SIZE);
    if(!label) {
        fprintf(stderr, "ERROR in new_label(), calloc() is null.\n");
        return NULL;
    }

    label->texture = texture;
    label->transformable.position.x = x;
    label->transformable.position.y = y;
    label->transformable.dimensions.width = width;
    label->transformable.dimensions.height = height;
    label->transformable.scale.width = 1;
    label->transformable.scale.height = 1;
    label->color.a = 255;

    return label;
}

void set_texture_label(Label label, Texture texture) {
    if(label && texture) {
        label->texture = texture;
        label->transformable.dimensions = get_texture_size(texture);
    }
}

void draw_label(Renderer renderer, Label label) {
    const Point center = {label->transformable.dimensions.width / 2, label->transformable.dimensions.height / 2};
    const Rectangle dest_rectangle = {
        label->transformable.position.x,
        label->transformable.position.y,
        label->transformable.dimensions.width * label->transformable.scale.width,
        label->transformable.dimensions.height * label->transformable.scale.height
    };

    SDL_RenderCopyEx(renderer, label->texture, NULL, &dest_rectangle, label->transformable.rotation, &center, SDL_FLIP_NONE);
}

void delete_label(void *label) {
    Label to_delete = (Label) label;
    if(to_delete) {
        free(to_delete);
    }
}
