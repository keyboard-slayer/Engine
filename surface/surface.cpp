#include "surface.h"

Surface::Surface(SDL_Surface* surface)
{
  this->surface = surface;
}

Surface::Surface(int width, int height)
{
  this->surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
}

void Surface::fill(int r, int g, int b)
{
  SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, r, g, b));
}

Surface Surface::copy(void)
{
  SDL_Surface* new_surface = SDL_ConvertSurface(this->surface, this->surface->format, this->surface->flags);
  return Surface(new_surface);
}

std::tuple<int, int> Surface::get_size(void)
{
  return std::make_tuple(this->surface->h, this->surface->w);
}

int Surface::get_height(void)
{
  return this->surface->h;
}

Rect Surface::blit(Surface surface, int x, int y)
{
  Rect rect = {x, y, surface.raw()->w, surface.raw()->h};
  SDL_BlitSurface(surface.raw(), NULL, this->surface, &rect);

  return rect;
}

int Surface::get_width(void)
{
  return this->surface->w;
}

bool Surface::is_null(void)
{
  return this->surface == NULL;
}

SDL_Surface* Surface::raw(void) {
  return this->surface;
}
