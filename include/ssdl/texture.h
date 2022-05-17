//
// Created by xRockmetalx
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <ssdl/types.h>

Texture new_sprite_texture(Renderer renderer, const char *filename);

Texture new_label_texture(Renderer renderer, Font font, const char *text, const Color color);

Texture new_rectangle_texture(Renderer renderer, int width, int height, int border_size, Color color, Color outline_color);

Dimensions get_texture_size(Texture texture);

void delete_texture(void *texture);

#endif // TEXTURE_H
