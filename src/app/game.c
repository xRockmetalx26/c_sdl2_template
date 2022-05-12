#include <app/game.h>

#include <stdio.h>

#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>

#include <app/render_window.h>
#include <app/scene_manager.h>
#include <app/scene.h>

Game* new_game(const char *title, const char *icon, const int width, const int height) {
    Game *game = (Game*) malloc(sizeof (Game));

    if(!game) {
        puts("ERROR new_game().");
        exit(EXIT_FAILURE);
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        puts("ERROR SDL_Init().");
        exit(EXIT_FAILURE);
    }

    if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP | IMG_INIT_TIF) < 0) {
        puts("ERROR SDL_Init().");
        exit(EXIT_FAILURE);
    }

    if(TTF_Init() < 0) {
        puts("ERROR TTF_Init().");
        exit(EXIT_FAILURE);
    }

    game->render_window = new_render_window(title, icon, width, height);
    game->scene_manager = new_scene_manager();

    return game;
}

void run(Game *game) {
    while(contains_scene(game->scene_manager)) {
        Scene *current_scene = game->scene_manager->current_scene;
        current_scene->_init(game->render_window->renderer);

        while(current_scene->running) {
            current_scene->_handle_events(current_scene, game->scene_manager);

            if(!current_scene->pause) {
                current_scene->_update();
            }

            current_scene->_render(game->render_window->renderer);
        }

        switch_scene(game->scene_manager);
    }

    delete_game(game);
}

void delete_game(Game *game) {
    if(game) {
        delete_render_window(game->render_window);
        delete_scene_manager(game->scene_manager);
        free(game);
    }

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
