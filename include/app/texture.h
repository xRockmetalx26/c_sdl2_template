//
// Created by xRockmetalx
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <sdl2/SDL_rect.h>

typedef struct SDL_Texture SDL_Texture;

void delete_texture(SDL_Texture *texture);

SDL_Rect get_texture_size(SDL_Texture *texture);

#endif // TEXTURE_H
