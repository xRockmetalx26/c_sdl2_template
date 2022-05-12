//
// Created by xRockmetalx
//

#ifndef SCENE_H
#define SCENE_H

#include <stdbool.h>

typedef struct SceneManager SceneManager;
typedef struct SDL_Renderer SDL_Renderer;

typedef struct Scene {
    void (*_init)(SDL_Renderer *);
    void (*_handle_events)(struct Scene *, SceneManager *);
    void (*_update)();
    void (*_render)(SDL_Renderer *);
    void (*_delete)(struct Scene *);

    bool running;
    bool pause;
} Scene;

#endif // SCENE_H
