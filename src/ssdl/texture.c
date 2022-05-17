//
// Created by xRockmetalx
//

#include <ssdl/texture.h>

#include <stdlib.h>
#include <stdio.h>

#include <ssdl/types.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_render.h>
#include <sdl2/SDL_ttf.h>

#include <ssdl/font.h>
#include <ssdl/dimensions.h>
#include <ssdl/position.h>

Texture new_sprite_texture(Renderer renderer, const char *filename) {
    if(!renderer) {
        fprintf(stderr, "ERROR in new_sprite_texture(), renderer is null.\n");
        return NULL;
    }

    if(!filename) {
        fprintf(stderr, "ERROR in new_sprite_texture(), filename is null.\n");
        return NULL;
    }

    Surface surface = IMG_Load(filename);
    if(!surface) {
        fprintf(stderr, "ERROR in new_sprite_texture(), IMG_Load() is null.\n");
        return NULL;
    }

    Texture texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture) {
        fprintf(stderr, "ERROR in new_sprite_texture(), SDL_CreateTextureFromSurface() is null.\n");
        return NULL;
    }

    SDL_FreeSurface(surface);

    return texture;
}

Texture new_label_texture(Renderer renderer, Font font, const char *text, const Color color) {
    if(!renderer) {
        fprintf(stderr, "ERROR in new_label_texture(), renderer is null.\n");
        return NULL;
    }

    if(!font) {
        fprintf(stderr, "ERROR in new_label_texture(), font is null.\n");
        return NULL;
    }

    if(!text) {
        fprintf(stderr, "ERROR in new_label_texture(), text is null.\n");
        return NULL;
    }

    Surface surface = TTF_RenderText_Solid(font->ttf, text, color);
    if(!surface) {
        fprintf(stderr, "ERROR in new_sprite_texture(), TTF_RenderText_Solid() is null.\n");
        return NULL;
    }

    Texture texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture) {
        fprintf(stderr, "ERROR in new_label_texture(), SDL_CreateTextureFromSurface() is null.\n");
        return NULL;
    }

    SDL_FreeSurface(surface);

    return texture;
}

Texture new_rectangle_texture(SDL_Renderer *renderer, const int width, const int height, const int border_size, const Color color, const Color outline_color) {
    if(!renderer) {
        fprintf(stderr, "ERROR in new_rectangle_texture(), renderer is null.\n");
        return NULL;
    }

    Texture texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        width,
        height
    );
    if(!texture) {
        fprintf(stderr, "ERROR in new_rectangle_texture(), SDL_CreateTexture() is null.\n");
        return NULL;
    }

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer, texture);

    SDL_SetRenderDrawColor(renderer, outline_color.r, outline_color.g, outline_color.b, outline_color.a);
    SDL_RenderFillRect(renderer, NULL);

    Rectangle rectangle = {
        border_size,
        border_size,
        width - border_size * 2,
        height - border_size * 2
    };

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rectangle);

    SDL_SetRenderTarget(renderer, NULL);

    return texture;
}

Dimensions get_texture_size(Texture texture) {
    Dimensions dimensions;

    SDL_QueryTexture(texture, NULL, NULL, &dimensions.width, &dimensions.height);

    return dimensions;
}

void delete_texture(void *texture) {
    Texture to_delete = (Texture) texture;
    if(to_delete) {
        SDL_DestroyTexture(to_delete);
    }
}
