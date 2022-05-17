//
// Created by xRockmetalx
//

#include <ssdl/transformable.h>

void move_transformable(Transformable *transformable, const int dx, const int dy) {
    transformable->position.x += dx;
    transformable->position.y += dy;
}
