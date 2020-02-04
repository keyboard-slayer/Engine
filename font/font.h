#ifndef ENGINE_FONT_H
#define ENGINE_FONT_H


#include "../includes.h"
#include "../surface/surface.h"

class Font 
{
	private:
		TTF_Font* font = NULL;
		Surface surface = NULL;
		Color color;
	
	public:
		Font(const char* path, int size);
		Font(const char* path, int size, Color color);
		Font(const char* path, int size, int r, int g, int b);

		void init(const char* path, int size);
		void render(const char* text);
		Surface get_surface(void);
};

#endif
