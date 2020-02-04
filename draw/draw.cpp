#include "draw.h"

Rect draw_rect(Color color, Surface surface, Rect rect)
{
  Surface rect_surface = Surface(rect.w, rect.h);
  rect_surface.fill(color.r, color.g, color.b);

  printf("(%d, %d)\n", rect.x, rect.y);

  return surface.blit(rect_surface, rect.x, rect.y);
}

Rect draw_rect(Color color, Screen screen, Rect rect)
{
  return draw_rect(color, screen.get_surface(), rect);
}
