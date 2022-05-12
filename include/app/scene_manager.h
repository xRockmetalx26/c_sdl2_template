//
// Created by xRockmetalx
//

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <stdbool.h>

typedef struct Scene Scene;
typedef struct SceneManager SceneManager;

typedef struct SceneManager {
    Scene *current_scene;
    Scene *next_scene;
} SceneManager;

SceneManager* new_scene_manager();

void set_next_scene(SceneManager *scene_manager, Scene *scene);

void switch_scene(SceneManager *scene_manager);

bool contains_scene(SceneManager *scene_manager);

void delete_scene_manager(SceneManager *scene_manager);

#endif // SCENE_MANAGER_H
