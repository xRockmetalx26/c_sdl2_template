//
// Created by xRockmetalx
//

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Window SDL_Window;
typedef struct SDL_Surface SDL_Surface;

typedef struct RenderWindow {
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Surface *window_icon;
} RenderWindow;

RenderWindow* new_render_window(const char *title, const char *icon, int width, int height);

void delete_render_window(RenderWindow *render_window);

#endif // RENDER_WINDOW_H
