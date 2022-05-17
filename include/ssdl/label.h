//
// Created by xRockmetalx
//

#ifndef LABEL_H
#define LABEL_H

#define LABEL_SIZE sizeof (struct _Label)

#include <ssdl/types.h>
#include <ssdl/transformable.h>

struct _Label {
    Texture texture;
    Transformable transformable;
    Color color;

    char text[1025];
};

Label new_label(Texture texture, int x, int y, int width, int height);

void set_texture_label(Label label, Texture texture);

void draw_label(Renderer renderer, Label label);

void delete_label(void *label);

#endif // LABEL_H
