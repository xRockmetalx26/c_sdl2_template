//
// Created by xRockmetalx
//

#include <ssdl/game.h>

#include <stdio.h>

#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>

#include <ssdl/render_window.h>
#include <ssdl/scene_manager.h>
#include <ssdl/scene.h>
#include <ssdl/dimensions.h>

Game new_game(Scene (*scene_main)(), const char *window_title, const char *window_icon, int window_width, int window_height) {
    if(!scene_main) {
        fprintf(stderr, "ERROR in new_game(), scene_main() is null.\n");
        return NULL;
    }

    Game game = (Game) malloc(GAME_SIZE);
    if(!game) {
        fprintf(stderr, "ERROR in new_game(), malloc() is null.\n");
        return NULL;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "ERROR in SDL_Init().\n");
        return NULL;
    }

    if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP | IMG_INIT_TIF) < 0) {
        fprintf(stderr, "ERROR in SDL_Init().\n");
        return NULL;
    }

    if(TTF_Init() < 0) {
        fprintf(stderr, "ERROR in TTF_Init().\n");
        return NULL;
    }

    game->render_window = new_render_window(window_title, window_icon, window_width, window_height);
    game->scene_manager = new_scene_manager(scene_main);

    return game;
}

void run(Game game) {
    if(!game) {
        fprintf(stderr, "ERROR in run(), game is null.\n");
        return;
    }

    SceneManager scene_manager = game->scene_manager;

    while(scene_manager->scene_current) {
        Scene scene_current = scene_manager->scene_current;
        if(!scene_current->_init(game->render_window->renderer)) {
            fprintf(stderr, "ERROR in run(), Scene->_init() is false.\n");
            return;
        }

        while(scene_current->running) {
            scene_current->_handle_events(scene_current, scene_manager);

            if(!scene_current->pause) {
                scene_current->_update();
            }

            scene_current->_render(game->render_window->renderer);
        }

        scene_manager->scene_current->_delete(scene_manager->scene_current);
        scene_manager->scene_current = scene_manager->scene_next;
    }

    delete_game(game);
}

void delete_game(void *game) {
    Game to_delete = (Game) game;

    if(to_delete) {
        delete_render_window(to_delete->render_window);
        delete_scene_manager(to_delete->scene_manager);
        free(to_delete);
    }

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
