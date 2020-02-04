#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H 

#include "../includes.h"

class Event {
 private:
  SDL_Event e;
  bool allow_key_repeat;
  int delta_time_key;
  char last_key_time;

 public:
  Event(SDL_Event e, bool allow_key_repeat, int delta_time_key);
  Event(void);

  bool operator!= (int type);
  bool operator== (int type);
  Rect get_rect(void);
  
  Key get_key(void);
  SDL_Event raw(void);
};

#endif
