//
// Created by xRockmetalx
//

#include <app/scene_manager.h>

#include <stdio.h>
#include <stdlib.h>

#include <app/scene_main.h>

SceneManager* new_scene_manager() {
    SceneManager *scene_manager = (SceneManager*) malloc(sizeof (SceneManager));

    if(!scene_manager) {
        puts("ERROR new_scene_manager().");
        exit(EXIT_FAILURE);
    }

    scene_manager->current_scene = (Scene*) new_scene_main();

    if(!scene_manager->current_scene) {
        puts("ERROR new_scene_main().");
        exit(EXIT_FAILURE);
    }

    return scene_manager;
}

void set_next_scene(SceneManager *scene_manager, Scene *scene) {
    scene_manager->next_scene = scene;
}

void switch_scene(SceneManager *scene_manager) {
    scene_manager->current_scene->_delete(scene_manager->current_scene);
    scene_manager->current_scene = scene_manager->next_scene;
}

bool contains_scene(SceneManager *scene_manager) {
    return scene_manager->current_scene ? true : false;
}

void delete_scene_manager(SceneManager *scene_manager) {
    free(scene_manager);
}
