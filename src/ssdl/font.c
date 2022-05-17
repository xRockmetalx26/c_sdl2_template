//
// Created by xRockmetalx
//

#include <ssdl/font.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sdl2/SDL_ttf.h>

Font new_font(const char *filename, const int point_size) {
    if(!filename) {
        fprintf(stderr, "ERROR in new_font(), filename is null.\n");
        return NULL;
    }

    Font font = (Font) calloc(1, FONT_SIZE);

    if(!font) {
        fprintf(stderr, "ERROR in new_font(), calloc() is null.\n");
        return NULL;
    }

    font->ttf = TTF_OpenFont(filename, point_size);

    if(!font->ttf) {
        fprintf(stderr, "ERROR in new_font(), TTF_OpenFont() is null.\n");
        return NULL;
    }

    strncpy(font->filename, filename, 256);

    font->point_size = point_size;

    return font;
}

void delete_font(void *font) {
    Font to_delete = (Font) font;

    if(to_delete) {
        if(to_delete->ttf) {
            TTF_CloseFont(to_delete->ttf);
        }

        free(to_delete);
    }
}
