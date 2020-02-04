#include "font.h"

void Font::init(const char* path, int size)
{
	if(TTF_Init() != 0) {
		fprintf(stderr, "Failed to initialize SDL_TTF !\nLOG:\n%s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	this->font = TTF_OpenFont(path, size);

	if(this->font == NULL) {
		fprintf(stderr, "Failed to load %s !\n");
		exit(EXIT_FAILURE);
	}
}
Font::Font(const char* path, int size)
{
	init(path, size);
	this->color = (Color){0, 0, 0};
}

Font::Font(const char* path, int size, Color color)
{
	init(path, size);
	this->color = color;
}

Font::Font(const char* path, int size, int r, int g, int b)
{
	init(path, size);
	this->color = (Color){r, g, b};
}


void Font::render(const char* txt)
{
	SDL_Color color = {this->color.r, this->color.g, this->color.b};
	this->surface = TTF_RenderText_Blended(this->font, txt, color);
}

Surface Font::get_surface(void)
{
	return this->surface;
}


