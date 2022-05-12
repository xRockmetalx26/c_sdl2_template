//
// Created by xRockmetalx
//

#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include <app/scene.h>

typedef struct SceneManager SceneManager;
typedef struct SDL_Renderer SDL_Renderer;
typedef struct Sprite Sprite;

Scene* new_scene_main();

void init_main();

void handle_events_main(Scene *scene, SceneManager *scene_manager);

void update_main();

void render_main(SDL_Renderer *renderer);

void delete_main();

#endif // SCENE_MAIN_H
