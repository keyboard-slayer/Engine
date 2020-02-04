#include "screen.h"

Screen::Screen(int width, int height, const char* title)
{
  int imgFlags = 0;
  
  this->width = width;
  this->height = height;

  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL Couldn't initialize !\nLog:\n%s\n\n", SDL_GetError());
    atexit(SDL_Quit);
  }

  this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

  if(this->window == NULL) {
    fprintf(stderr, "Window couldn't be created !\nLog:\n%s\n\n", SDL_GetError());
    atexit(SDL_Quit);
  }
  
  this->surface = Surface(SDL_GetWindowSurface(window));
  this->surface.fill(0, 0, 0);

  imgFlags = IMG_INIT_PNG;

  if(!(IMG_Init(imgFlags) & imgFlags)) {
    fprintf(stderr, "SDL_Image couldn't initialize !\nLog: \n%s\n\n", IMG_GetError());
  }
}

void Screen::update(void)
{
  SDL_UpdateWindowSurface(window);
}

void Screen::fill(int r, int g, int b)
{
  this->surface.fill(r, g, b);
}

void Screen::quit(void)
{
  atexit(SDL_Quit);
  exit(EXIT_SUCCESS);
}

Surface Screen::get_surface(void)
{
  return this->surface;
}

std::tuple<int, int> Screen::get_window_size(void)
{
  return std::make_tuple(this->width, this->height);
}

Rect Screen::blit(Surface surface, int x, int y)
{
  return this->surface.blit(surface, x, y);
}

Event Screen::get_event(void) 
{
  Event e;
  SDL_Event event;
  
  SDL_PollEvent(&event);
  e = Event(event, this->allow_key_repeat, this->delta_time_key);

  return e;
}

void Screen::enable_key_repeat(int delta_time) 
{
  this->allow_key_repeat = true;
  this->delta_time_key = delta_time;
}
