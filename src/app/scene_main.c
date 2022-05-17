//
// Created by xRockmetalx
//

#include <app/scene_main.h>

#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_render.h>
#include <ssdl/scene.h>
#include <ssdl/render_window.h>
#include <ssdl/scene_manager.h>
#include <ssdl/sprite.h>
#include <ssdl/label.h>
#include <ssdl/rectangle_shape.h>
#include <ssdl/font.h>
#include <ssdl/texture.h>

Sprite sprite = NULL;
Label label = NULL;
RectangleShape rectangle_shape = NULL;

Scene new_scene_main() {
    Scene scene_main = (Scene) calloc(1, SCENE_SIZE);
    if(!scene_main) {
        fprintf(stderr, "ERROR in new_scene_main(), calloc() is null.\n");
        return NULL;
    }

    scene_main->running = true;
    scene_main->_init = init_main;
    scene_main->_handle_events = handle_events_main;
    scene_main->_update = update_main;
    scene_main->_render = render_main;
    scene_main->_delete = delete_main;

    return scene_main;
}

bool init_main(Renderer renderer) {
    Texture texture = new_sprite_texture(renderer, "assets/images/icon.png");
    sprite = new_sprite(texture, 0, 0, 128, 128);

    Font font = new_font("assets/fonts/default.ttf", 14);
    const Color color = {255, 0, 0, 255};
    texture = new_label_texture(renderer, font, "SSDL Test", color);
    label = new_label(texture, 128, 128, 256, 64);

    const Color color_1 = {255, 0, 0, 255};
    const Color outline_color = {0, 255, 0, 255};
    texture = new_rectangle_texture(renderer, 128, 128, 6, color_1, outline_color);
    rectangle_shape = new_rectangle_shape(texture, 384, 192, 128, 128);

    return true;
}

void handle_events_main(Scene scene, SceneManager scene_manager) {
    Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                scene->running = false;
                scene_manager->scene_next = NULL;
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
    const unsigned char *keys = SDL_GetKeyboardState(NULL);

    if(keys[SDL_SCANCODE_A]) {
        move_transformable(&sprite->transformable, -4, 0);
    }

    if(keys[SDL_SCANCODE_D]) {
        move_transformable(&sprite->transformable, 4, 0);
    }

    if(keys[SDL_SCANCODE_S]) {
        move_transformable(&sprite->transformable, 0, 4);
    }

    if(keys[SDL_SCANCODE_W]) {
        move_transformable(&sprite->transformable, 0, -4);
    }

    sprite->transformable.rotation += 2;
    label->transformable.rotation -= 2;
    rectangle_shape->transformable.rotation += 2;
}

void render_main(Renderer renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //BEGIN RENDER

    draw_sprite(renderer, sprite);
    draw_label(renderer, label);
    draw_rectangle_shape(renderer, rectangle_shape);

    //END RENDER

    SDL_RenderPresent(renderer);
}

void delete_main(void *scene_main) {
    Scene to_delete = (Scene) scene_main;

    if(to_delete) {
        delete_sprite(sprite);
        delete_label(label);
        delete_rectangle_shape(rectangle_shape);
        free(to_delete);
    }
}
