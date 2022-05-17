//
// Created by xRockmetalx
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#define TRANSFORMABLE_SIZE sizeof (struct _Transformable)

#include <ssdl/types.h>
#include <ssdl/position.h>
#include <ssdl/dimensions.h>

struct _Transformable {
    Position position;
    Dimensions dimensions;
    Dimensions scale;

    float rotation;
};

void move_transformable(Transformable *transformable, int dx, int dy);

#endif // TRANSFORMABLE_H
