#include <app/texture.h>

#include <sdl2/SDL_render.h>

void delete_texture(SDL_Texture *texture) {
    if(texture) {
        SDL_DestroyTexture(texture);
    }
}

SDL_Rect get_texture_size(SDL_Texture *texture) {
    SDL_Rect rectangle = {0};

    SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);

    return rectangle;
}
