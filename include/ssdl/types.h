//
// Created by xRockmetalx
//

#ifndef SSDL_TYPES_H
#define SSDL_TYPES_H

#include <sdl2/SDL_events.h>
#include <sdl2/SDL_rect.h>
#include <sdl2/SDL_pixels.h>
#include <stdbool.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct _TTF_Font *TTF;
typedef struct SDL_Window *Window;
typedef struct SDL_Renderer *Renderer;
typedef struct SDL_Texture *Texture;
typedef struct SDL_Surface *Surface;
typedef union SDL_Event Event;
typedef struct SDL_Rect Rectangle;
typedef struct SDL_Color Color;
typedef struct SDL_Point Point;

typedef struct _Game *Game;
typedef struct _SceneManager *SceneManager;
typedef struct _RenderWindow *RenderWindow;
typedef struct _Scene *Scene;


typedef struct _Sprite *Sprite;
typedef struct _Label *Label;
typedef struct _RectangleShape *RectangleShape;
typedef struct _Font *Font;

typedef struct _Position Position;
typedef struct _Dimensions Dimensions;
typedef struct _Transformable Transformable;

#endif // SSDL_TYPES_H
