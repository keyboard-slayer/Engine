#ifndef ENGINE_DRAW_H
#define ENGINE_DRAW_H

#include "../surface/surface.h"
#include "../screen/screen.h"
#include "../includes.h"

Rect draw_rect(Color color, Surface surface, Rect rect);
Rect draw_rect(Color color, Screen screen, Rect rect);

#endif
