//
// Created by xRockmetalx
//

#ifndef SCENE_H
#define SCENE_H

#define SCENE_SIZE sizeof (struct _Scene)

#include <ssdl/types.h>

struct _Scene {
    bool (*_init)(Renderer);
    void (*_handle_events)(Scene, SceneManager);
    void (*_update)();
    void (*_render)(Renderer);
    void (*_delete)(void*);

    bool running;
    bool pause;
};

#endif // SCENE_H
