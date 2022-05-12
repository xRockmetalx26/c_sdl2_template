//
// Created by xRockmetalx
//

#include <stdlib.h>
#include <stdio.h>

#include <app/game.h>

int main() {
    Game *game = new_game("SDL2 Template", "assets/images/icon.png", 1024, 680);

    run(game);

    return EXIT_SUCCESS;
}
