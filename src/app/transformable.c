//
// Created by xRockmetalx
//

#include <app/transformable.h>

void move(Transformable *transformable, const int dx, const int dy) {
    transformable->rectangle.x += dx;
    transformable->rectangle.y += dy;
}
