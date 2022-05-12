//
// Created by xRockmetalx
//

#include <app/render_window.h>

#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_Render.h>
#include <sdl2/SDL_image.h>

RenderWindow* new_render_window(const char *title, const char *icon, const int width, const int height) {
    RenderWindow *render_window = (RenderWindow*) malloc(sizeof(RenderWindow));

    if(!render_window) {
        puts("ERROR new_render_window().");
        exit(EXIT_FAILURE);
    }

    render_window->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(!render_window->window) {
        puts("ERROR SDL_CreateWindow().");
        exit(EXIT_FAILURE);
    }

    render_window->renderer = SDL_CreateRenderer(render_window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!render_window->renderer) {
        puts("ERROR SDL_CreateRenderer().");
        exit(EXIT_FAILURE);
    }

    render_window->window_icon = IMG_Load(icon);
    SDL_SetWindowIcon(render_window->window, render_window->window_icon);

    return render_window;
}

void delete_render_window(RenderWindow *render_window) {
    SDL_DestroyWindow(render_window->window);
    SDL_DestroyRenderer(render_window->renderer);
    SDL_FreeSurface(render_window->window_icon);
    free(render_window);
}
