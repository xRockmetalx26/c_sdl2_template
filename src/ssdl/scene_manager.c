//
// Created by xRockmetalx
//

#include <ssdl/scene_manager.h>

#include <stdio.h>
#include <stdlib.h>

#include <ssdl/scene.h>

SceneManager new_scene_manager(Scene (*scene_main)()) {
    SceneManager scene_manager = (SceneManager) calloc(1, SCENE_MANAGER_SIZE);
    if(!scene_manager) {
        fprintf(stderr, "ERROR in new_scene_manager(), calloc() is null.\n");
        return NULL;
    }

    scene_manager->scene_current = scene_main();
    if(!scene_manager->scene_current) {
        fprintf(stderr, "ERROR in new_scene_manager(), scene_main() is null.\n");
        return NULL;
    }

    return scene_manager;
}

void delete_scene_manager(void *scene_manager) {
    SceneManager to_delete = (SceneManager) scene_manager;
    if(to_delete) {
        free(to_delete);
    }
}
