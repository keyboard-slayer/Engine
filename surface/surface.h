#ifndef ENGINE_SURFACE_H
#define ENGINE_SURFACE_H

#include "../includes.h"

class Surface {
 private:
  SDL_Surface* surface = NULL;

 public:
  Surface(SDL_Surface* surface);
  Surface(int width, int height);
  Surface(void);
  
  Surface copy(void);
  std::tuple<int, int> get_size(void);
  int get_height(void);
  int get_width(void);
  bool is_null(void);
  void fill(int r, int g, int b);
  Rect blit(Surface surface, int x, int y);
  SDL_Surface* raw(void);
};

#endif
