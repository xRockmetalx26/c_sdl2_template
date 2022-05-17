//
// Created by xRockmetalx
//

#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include <ssdl/types.h>

Scene new_scene_main();

bool init_main();

void handle_events_main(Scene scene, SceneManager scene_manager);

void update_main();

void render_main(Renderer renderer);

void delete_main(void *scene_main);

#endif // SCENE_MAIN_H
