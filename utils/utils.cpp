#include "utils.h"

Surface engine_load_image(const char* filepath, Screen window)
{
  
  SDL_Surface* loaded_surface = NULL;
  Surface surface = NULL;
  
  loaded_surface = IMG_Load(filepath);

  if(loaded_surface == NULL) {
    fprintf(stderr, "Unable to load image %s !\nLog:\n%s\n\n", filepath, IMG_GetError());
  }

  surface = Surface(SDL_ConvertSurface(loaded_surface, window.get_surface().raw()->format, 0));

  if(surface.is_null()) {
    fprintf(stderr, "Unable to optimize the image %s !\nLog:\n%s\n\n", filepath, SDL_GetError());
  }
 
  SDL_FreeSurface(loaded_surface);
  
  return surface;
}

bool rect_collide(Rect A, Rect B)
{
  SDL_bool result = SDL_HasIntersection(&A, &B);

  return result == SDL_TRUE;
}
