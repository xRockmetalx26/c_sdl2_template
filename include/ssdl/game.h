//
// Created by xRockmetalx
//

#ifndef GAME_H
#define GAME_H

#define GAME_SIZE sizeof (struct _Game)

#include <ssdl/types.h>

struct _Game {
    RenderWindow render_window;
    SceneManager scene_manager;
};

Game new_game(Scene (*scene_main)(), const char *window_title, const char *window_icon, int window_width, int window_height);

void run(Game game);

void delete_game(void *game);

#endif // GAME_H
