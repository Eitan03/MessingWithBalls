#pragma once
#include <string>
#include <SDL.h>

#include "./MySDL.h"

class MyTexture
{
public:
	MyTexture(std::string path, MySDL* mySDL);
	~MyTexture();

	int getWidth() { return this->size.x; }
	int getHeight() { return this->size.y; }

	void render(Point<int> size, Point<int> position);
private:
	MySDL* mySDL;
	SDL_Texture* sdl_texture;
	Point<int> size;
};

