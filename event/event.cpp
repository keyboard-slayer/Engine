#include "event.h"

Event::Event(SDL_Event e, bool allow_key_repeat, int delta_time_key) 
{
  this->e = e;
  this->allow_key_repeat = allow_key_repeat;
  this->delta_time_key = delta_time_key;
}

Event::Event()
{
  SDL_Event e; 
  
  this->e = e;
  this->allow_key_repeat = false;
  this->delta_time_key = 0;
}

bool Event::operator!=(int type)
{
  return this->e.type != type;
}

bool Event::operator==(int type)
{
  return this->e.type == type;
}

SDL_Event Event::raw(void) 
{
  return this->e;
}

Key Event::get_key(void) 
{
  if(this->e.key.repeat != 0 && !this->allow_key_repeat)
    return SDLK_UNKNOWN;

  if(this->delta_time_key != 0) {
    if(this->e.key.timestamp % this->delta_time_key > this->delta_time_key / 100 && this->e.key.repeat)
      return SDLK_UNKNOWN;
  }

  this->last_key_time = this->e.key.timestamp;
  return this->e.key.keysym.sym;
}

Rect Event::get_rect(void)
{
  const int h = 32;
  const int w = 32;

  if(this->e.type != SDL_MOUSEMOTION) {
    fprintf(stderr, "Bad function call ! (SDL_MouseMotionEvent)");
    exit(EXIT_FAILURE);
  }
  
  Rect mouse_rect = {this->e.motion.x, this->e.motion.y, w, h};
  
  return mouse_rect; 
}
