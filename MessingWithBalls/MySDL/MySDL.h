#pragma once
#include <SDL.h>
#include "../Utils/Point.h"


class MyTexture;

class MySDL
{
	friend class MyTexture;
public:

	MySDL(Point<int> windowSize);
	~MySDL();


	void clearWindow();
	void renderWindow();
private:
	void init(Point<int> windowSize);
	void close();

	SDL_Window* sdl_window;
	SDL_Renderer* sdl_renderer;
};

