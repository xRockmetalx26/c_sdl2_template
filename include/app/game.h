//
// Created by xRockmetalx
//

#ifndef GAME_H
#define GAME_H

typedef struct SceneManager SceneManager;
typedef struct RenderWindow RenderWindow;

typedef struct Game {
    RenderWindow *render_window;
    SceneManager *scene_manager;
} Game;

Game* new_game(const char *title, const char *icon, int width, int height);

void run(Game *game);

void delete_game();

#endif // GAME_H
