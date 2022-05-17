//
// Created by xRockmetalx
//

#include <ssdl/render_window.h>

#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_Render.h>
#include <sdl2/SDL_image.h>

#include <ssdl/dimensions.h>

RenderWindow new_render_window(const char *title, const char *icon, const int width, const int height) {
    RenderWindow render_window = (RenderWindow) malloc(RENDER_WINDOW_SIZE);
    if(!render_window) {
        fprintf(stderr, "ERROR in new_render_window(), malloc() is null.\n");
        return NULL;
    }

    render_window->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(!render_window->window) {
        fprintf(stderr, "ERROR in new_render_window(), SDL_CreateWindow() is null.\n");
        return NULL;
    }

    render_window->renderer = SDL_CreateRenderer(render_window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!render_window->renderer) {
        fprintf(stderr, "ERROR in new_render_window(), SDL_CreateRenderer() is null.\n");
        return NULL;
    }

    render_window->icon = IMG_Load(icon);
    if(!render_window->icon) {
        fprintf(stderr, "ERROR in new_render_window(), IMG_Load() is null.\n");
        return NULL;
    }

    SDL_SetWindowIcon(render_window->window, render_window->icon);

    return render_window;
}

void delete_render_window(void *render_window) {
    RenderWindow to_delete = (RenderWindow) render_window;
    if(to_delete) {
        SDL_DestroyWindow(to_delete->window);
        SDL_DestroyRenderer(to_delete->renderer);
        SDL_FreeSurface(to_delete->icon);
        free(to_delete);
    }
}
