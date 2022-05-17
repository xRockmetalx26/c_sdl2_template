//
// Created by xRockmetalx
//

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#define SCENE_MANAGER_SIZE sizeof (struct _SceneManager)

#include <ssdl/types.h>

struct _SceneManager {
    Scene scene_current;
    Scene scene_next;
};

SceneManager new_scene_manager(Scene (*scene_main)());

void delete_scene_manager(void *scene_manager);

#endif // SCENE_MANAGER_H
