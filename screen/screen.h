#ifndef ENGINE_SCREEN_H
#define ENGINE_SCREEN_H

#include "../includes.h"
#include "../surface/surface.h"
#include "../event/event.h"

class Screen
{
 private:
  int width;
  int height;

  bool allow_key_repeat = false;
  int delta_time_key = 0;

  SDL_Window* window = NULL;
  Surface surface = NULL;

 public:
  Screen(int width, int height, const char* title);
  void quit(void);
  void update(void);
  void enable_key_repeat(int delta_time);
  void fill(int r, int g, int b);
  
  Event get_event(void);
  Rect blit(Surface surface, int x, int y);
  Surface get_surface(void);
  std::tuple<int, int> get_window_size(void);
};

#endif
