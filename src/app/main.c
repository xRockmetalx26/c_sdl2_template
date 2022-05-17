//
// Created by xRockmetalx
//

#include <stdlib.h>
#include <stdio.h>

#include <ssdl/game.h>
#include <app/scene_main.h>

int main() {
    Game game = new_game(new_scene_main, "SDL2 Template", "assets/images/icon.png", 1024, 680);

    run(game);

    return EXIT_SUCCESS;
}
