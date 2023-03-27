#pragma once
#include <string>
#include <SDL.h>

#include "./MySDL.h"

class MyTexture
{
public:
	MyTexture(std::string path, MySDL* mySDL);
	~MyTexture();

	int getWidth() { return this->width; }
	int getHeight() { return this->height; }

	void render(int x, int y);
private:
	MySDL* mySDL;
	SDL_Texture* sdl_texture;
	int width;
	int height;

};

