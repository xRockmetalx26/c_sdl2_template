//
// Created by xRockmetalx
//

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#define RENDER_WINDOW_SIZE sizeof (struct _RenderWindow)

#include <ssdl/types.h>

struct _RenderWindow {
    Window window;
    Renderer renderer;
    Surface icon;
};

RenderWindow new_render_window(const char *title, const char *icon, int width, int height);

void delete_render_window(void *render_window);

#endif // RENDER_WINDOW_H
