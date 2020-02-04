#ifndef ENGINE_UTILS_H
#define ENGINE_UTILS_H

#include "../includes.h"
#include "../screen/screen.h"
#include "../surface/surface.h"

typedef SDL_Rect Rect;

Surface engine_load_image(const char* filepath, Screen window);
bool rect_collide(Rect first, Rect second);

#endif
