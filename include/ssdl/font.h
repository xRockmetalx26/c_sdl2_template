//
// Created by xRockmetalx
//

#ifndef FONT_H
#define FONT_H

#define FONT_SIZE sizeof (struct _Font)

#include <ssdl/types.h>

struct _Font {
    TTF ttf;

    char filename[257];
    int point_size;
};

Font new_font(const char *filename, int point_size);

void delete_font(void *font);

#endif // FONT_H
