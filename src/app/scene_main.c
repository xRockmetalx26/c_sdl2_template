//
// Created by xRockmetalx
//

#include <app/scene_main.h>

#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_events.h>
#include <sdl2/SDL_render.h>

#include <stdbool.h>

#include <app/scene.h>
#include <app/render_window.h>
#include <app/scene_manager.h>
#include <app/sprite.h>
#include <app/label.h>
#include <app/rectangle_shape.h>

typedef struct SceneManager SceneManager;
typedef struct SDL_Renderer SDL_Renderer;

Sprite *sprite = NULL;
Label *label = NULL;
RectangleShape *rectangle_shape = NULL;

Scene* new_scene_main() {
    Scene *scene_main = (Scene*) malloc(sizeof (Scene));

    if(!scene_main) {
        puts("ERROR new_scene_main().");
        exit(EXIT_FAILURE);
    }

    scene_main->running = true;
    scene_main->pause = false;
    scene_main->_init = init_main;
    scene_main->_handle_events = handle_events_main;
    scene_main->_update = update_main;
    scene_main->_render = render_main;
    scene_main->_delete = delete_main;

    return scene_main;
}

void init_main(SDL_Renderer *renderer) {
    sprite = new_sprite(0, 0, 128, 128);
    load_image(renderer, sprite, "assets/images/icon.png");

    label = new_label(128, 128, 128, 64);
    label->color.b = 255;
    load_text(renderer, label, "assets/fonts/default.ttf", "SDL2 Template");

    rectangle_shape = new_rectangle_shape(256, 192, 128, 128);
    rectangle_shape->color_border.r = 255;
    rectangle_shape->color.b = 255;

    load_rgba(renderer, rectangle_shape);
}

void handle_events_main(Scene *scene, SceneManager *scene_manager) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                scene->running = false;
                set_next_scene(scene_manager, NULL);
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_SPACE)
                    scene->pause = !scene->pause;
                break;

            default: break;
        }
    }
}

void update_main() {
    const uint8_t* keys = SDL_GetKeyboardState(NULL);

    if(keys[SDL_SCANCODE_A]) {
        move(&sprite->transformable, -4.0, 0.0);
    }

    if(keys[SDL_SCANCODE_D]) {
        move(&sprite->transformable, 4.0, 0.0);
    }

    if(keys[SDL_SCANCODE_S]) {
        move(&sprite->transformable, 0.0, 4.0);
    }

    if(keys[SDL_SCANCODE_W]) {
        move(&sprite->transformable, 0.0, -4.0);
    }
}

void render_main(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //BEGIN RENDER

    draw_sprite(renderer, sprite);
    draw_label(renderer, label);
    draw_rectangle_shape(renderer, rectangle_shape);

    //END RENDER

    SDL_RenderPresent(renderer);
}

void delete_main() {
    delete_label(label);
    delete_sprite(sprite);
    delete_rectangle_shape(rectangle_shape);
}
